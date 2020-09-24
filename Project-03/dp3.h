/*
File:		dp3.h
Author:		Millard A. Arnold V
Started:	2020-09-21
Updated:	2020-09-21
Project:	CS-311 Project 3

Header file for Project 3 Functions

Using skeleton file 
provided by Glenn G. Chappell 
written on 2020-09-17
*/

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"		// For LLNode
#include <cstddef>		// For std::size_t
#include <functional>	// For std::function


/*
	function template lookup

	Takes index & node of a singly linked list.

	Returns value of the singly linked 
	list index forwards from head.
	
	Throws std::out_of_range error if 
	index is out of range
*/
template <typename ValueType>	// ValueType must be returnable.
ValueType lookup(const LLNode<ValueType> * head, std::size_t index)
{
	auto p = head;
	for (std::size_t i = 0; i < index && p!=nullptr; ++i)
	{
		p = p->_next;
	}
	if (p != nullptr)
	{
		return p->_data;
	}
	throw std::out_of_range("Function lookup: index out of range");
}

/*
	function didItThrow
	implementation in source file

	Takes function pointer or object 
	that acts like a function.
	
	Calls function with no parameters
	
	If thrown, sets threw to true & rethrows
	If does not throw, sets threw to false.

	pre:
		ff must have operator() defined
*/
void didItThrow(const std::function<void()> & ff, bool & threw);

/*
	function template checkSorted
	
	takes two forward iterators specifying range in standard manner

	return true if range is sorted in ascending order by operator<

	pre: 
		FDIter points to data with operator< defined
*/
template <typename FDIter>	// FDIter must point to a value & have operator++ defined
bool checkSorted(FDIter first, FDIter last)
{
	if (first == last)
	{
		return true; 
	}
	auto curr = *first;
	while (++first != last)
	{
		if (curr <= *first)
		{
			curr = *first;
			continue;
		}
		return false;
	}
    return true; 
}


/*
	function gcd
	implementation in source file
	
	takes two nonegative integers
	
	returns greatest common divisor of a & b
	uses Euclidean Algorithm
	
	pre:
		a >= 0
		b >= 0
		a != 0 || b != 0
*/
int gcd(int a, int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED

