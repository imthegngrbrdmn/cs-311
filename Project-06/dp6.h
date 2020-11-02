/*
	File:		dp6.h
	Author:		Millard A. Arnold V
	Started:	2020-11-02
	Updated:	2020-11-02
	Project:	CS-311 Project 6

	Header file for Project 6 functions
	*/

#ifndef DP6_H

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


template<typename KeyType, typename dataType>
class LLMap
{
public:
	using KVType = std::pair<KeyType, dataType>;
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
private:
	std::unique_ptr<LLNode2<KVType>> _data;
};

#endif