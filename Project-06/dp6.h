/*
	File:		dp6.h
	Author:		Millard A. Arnold V
	Started:	2020-11-02
	Updated:	2020-11-02
	Project:	CS-311 Project 6

	Header file for Project 6 functions
	*/

#ifndef DP6_H
#define DP6_H

#include <memory>
#include "llnode2.h"

/*
	ValType must be a value type held by an LLNode2 object

	reverseList function
	given unique_ptr to a Linked List or an 
	empty unique_ptr if the list is empty. 
	Reverses the list. A pointer to the new 
	list is returned via the reference parameter.

	Strong Guarantee
	Exception Neutral
*/
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>>& head)
{
	if (size(head) <= 1) return;
	std::unique_ptr<LLNode2<ValType>> newHead;
	while (head)
	{
		auto next = std::move(head->_next);
		auto oldHead = std::move(newHead);
		newHead = std::move(head);
		newHead->_next = std::move(oldHead);
		head = std::move(next);
	}
	head = std::move(newHead);
}

/*
	class LLMap
	Linked List holding an associative dataset
	invariants: none
*/
template<typename keyType, typename dataType>
class LLMap
{

/*
	Public Data Member Types
*/
public:
	// Type for key
	using key_type = keyType;
	
	//Type for data
	using data_type = dataType;
	
	//Key-Value type
	using KVType = std::pair<key_type, data_type>;
	
	//Type for size
	using size_type = std::size_t;

/*
	Default ctor and big 5
*/
public:
	/*
		Default ctor
		creates an empty dataset
		
		Strong Guarantee
		Exception Neutral
	*/
	LLMap()
	{

	}

	/*
		dctor
		
		No Throw Guarantee
		Exception Neutral
	*/
	~LLMap()
	{
		head.release();
	}

	/*
		copy ctor
		move ctor
		copy assignment operator
		move assignment operator
		
		All Deleted
	*/
	LLMap(const LLMap& other) = delete;
	LLMap(LLMap&& other) = delete;
	LLMap& operator=(const LLMap& other) = delete;
	LLMap& operator=(LLMap&& other) = delete;

/*
	public member functions
*/
public:
	/*
		member function size
		returns number fo key-value pairs in the dataset

		Strong Gurantee
		Exception Neutral
	*/
	size_type size() const noexcept
	{
		auto p = head.get();
		std::size_t counter = 0;
		while (p != nullptr)
		{
			++counter;
			p = p->_next.get();
		}
		return counter;
	}

	/*
		member function empty
		returns true if ther are no 
		key-value pairs in the dataset
		
		Strong Gurarantee
		Exception Neutral
	*/
	bool empty() const noexcept
	{
		return size() == 0;
	}

	/*
		member function find
		if key lies in dataset, returned 
		pointer points to associated value. 
		otherwise returns nullptr
		
		Strong Gurarantee
		Exception Neutral
	*/
	data_type* find(key_type key)
	{
		LLNode2<KVType>* p = head.get();
		while (p != nullptr)
		{
			if (p->_data.first == key)
			{
				return &p->_data.second;
			}
			p = p->_next.get();
		}
		return nullptr;
	}


	/*
		const member function find
		if key lies in dataset, returned
		pointer points to associated value.
		otherwise returns nullptr

		Strong Gurarantee
		Exception Neutral
	*/
	const data_type* find(key_type key) const
	{
		LLNode2<KVType>* p = head.get();
		while (p != nullptr)
		{
			if (p->_data.first == key)
			{
				return &p->_data.second;
			}
			p = p->_next.get();
		}
		return nullptr;
	}

	/*
		member function insert
		if equal key does not lie in the data 
		set, then the key-value pair is inserted. 
		if equal key does lie in the data set, 
		then existing key-value pair is replaced

		Strong Guarantee
		Exception Neutral
	*/
	void insert(key_type key, data_type data)
	{
		push_front(head, std::make_pair(key, data));
	}

	/*
		member function erase
		if equal key lies in the dataset
		key-value pair is removed
		otherwise does nothing
		
		Strong Guarantee
		Exception Neutral
	*/
	void erase(key_type key)
	{
		auto p = head.get();
		auto last = p;
		while (p != nullptr)
		{
			if (p->_data.first == key)
			{
				last->_next = std::move(p->_next);
				return;
			}
			last = p;
			p = p->_next.get();
		}
	}

	/*
		member function traverse
		passed function is called on each 
		key-value pair in the dataset

		Strong Guarantee
		Exception Neutral

		F must be a function or function like object 
		that takes parameters (key_type, data_type)
	*/
	template<typename F> 
	void traverse(F func)
	{
		auto p = head.get();
		while (p != nullptr)
		{
			func(p->_data.first, p->_data.second);
			p = p->_next.get();
		}
	}

/*
	private data member
*/
private:
	//head of the list managed by this class
	std::unique_ptr<LLNode2<KVType>> head;
};

#endif