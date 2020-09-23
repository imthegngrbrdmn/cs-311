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

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function


template <typename ValueType>
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
	throw std::out_of_range("index out of range");
}


void didItThrow(const std::function<void()> & ff,
                bool & threw);


template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
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


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED

