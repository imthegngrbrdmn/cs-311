/*
	File:		treesort.h
	Author:		Millard A. Arnold V
	Started:	2020-11-15
	Updated:	2020-11-15
	Project:	CS-311 Project 7

	Header file for treesort
*/

#ifndef TREESORT_H
#define TREESORT_H
#include <iterator>
//	For std::iterator_traits
#include <memory>
//	For std::unique_ptr, std::make_unique
#include <algorithm>
//	For std::move

/*
	Struct BSTreeNode
	Struct to hold a node of a binary search tree

	ValType must be a value type held by the BSTreeNode
	
	invariants:	
		_left points to the left node or nullptr
		_right points to the right node or nullptr
	*/
template<typename ValType>
struct BSTreeNode
{
	ValType						_data;				// Data for this node
	std::unique_ptr<BSTreeNode>	_left = nullptr;	// pointer to left node, empty if none
	std::unique_ptr<BSTreeNode>	_right = nullptr;	// pointer to right node, empty if none

	/*
		One Parameter Constructor
		creates a BSTreeNode with no children
		
		No Throw Guarantee
		Exception Neutral
	*/
	explicit BSTreeNode(const ValType& data)
		:_data(data)
	{}

	/*
		Default constructed dctor
	*/
	~BSTreeNode() = default;
	
	/*
		Delete default ctor, assignment ops, copy ctor, and move ctor
	*/
	BSTreeNode() = delete;
	BSTreeNode(const BSTreeNode& other) = delete;
	BSTreeNode(BSTreeNode&& other) = delete;
	BSTreeNode& operator=(const BSTreeNode& other) = delete;
	BSTreeNode& operator=(BSTreeNode&& other) = delete;
};

/*
	function insert
	Recursively inserts given item into an appropriate place of the binary search tree

	ValType must be the value type of the item and held by the BSTreeNode

	Exception Neutral
	Strong Guarantee
*/
template<typename ValType>
void insert(std::unique_ptr<BSTreeNode<ValType>>& head, const ValType& item)
{
	// If node is undefined, define and end.
	if (!head)
	{
		head = std::make_unique<BSTreeNode<ValType>>(item);
	}
	// If item is less than current node, retry with left child
	else if (item < head->_data)
	{
		insert(head->_left, item);
	}
	// If item is greater than or equal to current node, retry with right child
	else
	{
		insert(head->_right, item);
	}
}

/*
	function inorder_traverse
	recursively copies an inorder traversal 
	of the Binary Search Tree to the array 
	referenced by the given iterator
	
	pre:
		it must be a forward iterator to an array with at 
		least space of the nodes in the tree under head
	
	ValType must be the value type of the value pointed to 
	by the given iterator and the nodes of the Binary Search tree
	
	FDIter must be a forwards iterator
	
	Strong Guarantee
	Exception Neutral
*/
template<typename ValType, typename FDIter>
void inorder_traverse(std::unique_ptr<BSTreeNode<ValType>>& head, FDIter& it)
{
	if (head->_left)
	{
		inorder_traverse(head->_left, it);
	}
	if (head)
	{
		*it = head->_data;
		++it;
	}
	if (head->_right)
	{
		inorder_traverse(head->_right, it);
	}
}

/*
	function treeesort
	creates a binary search tree from the array referenced by first and last
	and copies the inorder traversal to the array referenced by first and last
	
	FDIter must be a forwards iterator
	
	Strong Guarantee
	Exception Neutral
*/
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
	std::unique_ptr<BSTreeNode<std::iterator_traits<FDIter>::value_type>> head;
	FDIter temp = first;
	while (temp != last)
	{
		insert(head, *temp);
		++temp;
	}
	if (head)
	{
		inorder_traverse(head, first);
	}
}

#endif