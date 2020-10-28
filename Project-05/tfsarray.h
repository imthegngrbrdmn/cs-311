/*
	File:		tfsarray.h
	Author:		Millard A. Arnold v
	Started:	2020-08-26
	Updated:	2020-08-26
	Project:	CS-311 Project 4

	Header file for Templated Frightfully Smart Array
*/

#ifndef TFSARRAY_H
#define TFSARRAY_H

#include<cstdlib>
#include<algorithm>

template<typename T>
class TFSArray
{
public:
	using value_type = T;
	using size_type = std::size_t;
	using iterator = value_type*;
	using const_iterator = const value_type*;
public:
	TFSArray()
		: _size(0), _arrayPtr(new value_type[0])
	{}

	~TFSArray()
	{
		delete[] _arrayPtr;
	}
	TFSArray(const TFSArray& other)
		: _size(other.size()), _arrayPtr(new value_type[other.size()])
	{
		std::copy(other.begin(), other.end(), _arrayPtr);
	}
	TFSArray(TFSArray&& other) noexcept
		: _size(other._size), _arrayPtr(other._arrayPtr)
	{
		other._arrayPtr = nullptr;
		other._size = 0;
	}
	TFSArray& operator=(const MSArray& other)
	{
		TFSArray copy_of_other(other);
		mswap(copy_of_other);
		return *this;
	}

public:
	value_type& operator[](size_type index)
	{
		return _arrayPtr[index];
	}
	size_type size()
	{
		return _size;
	}

	bool empty()
	{
		return 0 == _size;
	}

	void resize(size_type size)
	{
		//STUFF
	}

	iterator insert(iterator it, value_type val)
	{
		//STUFF
		return it;
	}

	iterator erase(iterator it)
	{
		//STUFF
		return it;
	}

	iterator begin()
	{
		return _arrayPtr;
	}

	iterator end()
	{
		return _arrayPtr + _size;
	}

	void push_back()
	{
		//STUFF
	}

	void pop_back()
	{
		//STUFF
	}

	void swap(TFSArray& other)
	{
		//STUFF
	}
private:
	void mswap(TFSArray& other) noexcept
	{
		std::swap(_arrayPtr, other._arrayPtr);
		std::swap(_size, other._size);
	}
private:
	value_type* _arrayPtr;
	size_type _size;
};
#endif