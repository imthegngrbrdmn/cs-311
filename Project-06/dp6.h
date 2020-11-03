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
	//STUFF
}


template<typename keyType, typename dataType>
class LLMap
{
public:
	using key_type = keyType;
	using data_type = dataType;
	using KVType = std::pair<key_type, data_type>;
	using size_type = std::size_t;
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
		member function size
		returns number fo key-value pairs in the dataset

		Strong Gurantee
		Exception Neutral
	*/
	size_type size()
	{
		return 0;
	}

	/*
		member function empty
		returns true if ther are no 
		key-value pairs in the dataset
		
		Strong Gurarantee
		Exception Neutral
	*/
	bool empty()
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
	std::unique_ptr<LLNode2<KVType>> find(key_type key)
	{
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

	}

	/*
		member function traverse
		passed function is called on each 
		key-value pair in the dataset

		Strong Guarantee
		Exception Neutral
	*/
	template<typename F_TRAVERSE> 
	void traverse(F_TRAVERSE func)
	{

	}

private:
	std::unique_ptr<LLNode2<KVType>> _data;
};

#endif