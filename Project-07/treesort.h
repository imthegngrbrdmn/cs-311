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

template<typename ValType>
struct BSTree
{
	ValType						_data;	// Data for this node
	std::unique_ptr<BSTree>		_left = nullptr;	// pointer to left node, empty if none
	std::unique_ptr<BSTree>		_right = nullptr;	// pointer to right node, empty if none

	explicit BSTree(const ValType& data)
		:_data(data)
	{}

	~BSTree() {}
	BSTree() = delete;
	BSTree(const BSTree& other) = delete;
	BSTree(BSTree&& other) = delete;
	BSTree& operator=(const BSTree& other) = delete;
	BSTree& operator=(BSTree&& other) = delete;
};

template<typename ValType>
void insert(std::unique_ptr<BSTree<ValType>>& head, const ValType& item)
{
	if (head == nullptr)
	{
		head = std::make_unique<BSTree<ValType>>(item);
	}
	else if (item < head->_data)
	{
		insert(head->_left, item);
	}
	else
	{
		insert(head->_right, item);
	}
}

template<typename ValType, typename FDIter>
void inorder_traverse(std::unique_ptr<BSTree<ValType>>& head, FDIter& it)
{
	if(head->_left) inorder_traverse(head->_left, it);
	if (head)
	{
		*it = head->_data;
		++it;
	}
	if(head->_right) inorder_traverse(head->_right, it);
}

template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
	using Value = typename std::iterator_traits<FDIter>::value_type;
	std::unique_ptr<BSTree<Value>> head;
	FDIter temp = first;
	while (temp != last)
	{
		insert(head, *temp);
		++temp;
	}
	temp = first;
	if (head)
	{
		inorder_traverse(head, temp);
	}
}

#endif