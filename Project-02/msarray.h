/*
File:		msarray.h
Author:		Millard A. Arnold V
Started:	2020-09-09
Updated:	2020-09-09
Project:	CS-311 Project 2

Header file for moderately smart array
*/

#ifndef MSARRAY_H
#define MSARRAY_H

#include <algorithm>
#include <stdexcept>
#include <cstddef>

template<typename T> 
class MSArray
{
public:
	using value_type = T;
	using size_type = std::size_t;
public:
	/*
		Default ctor
		Create MSArray of size 8
		All items should be default constucted
	*/
	MSArray()
		: _size(8), _arrayPtr(new value_type[8])
	{

	}
	
	/*
		1 Parameter ctor
		Pre: 
			non-negative integer giving number of items in array
		All items should be default constructed
	*/
	explicit MSArray(int size)
		: _size(size), _arrayPtr(new value_type[size])
	{

	}

	/*
		2 Parameter ctor
		Pre: 
			non-negative integer giving number of items in array
		All items should be set to value of second parameter
	*/
	MSArray(int size, value_type value)
		: _size(size), _arrayPtr(new value_type[size])
	{
		for (std::size_t i = 0; i < _size; ++i)
		{
			_arrayPtr[i] = value;
		}
	}

	//	Destructor
	~MSArray()
	{
		delete [] _arrayPtr;
	}
	//	Copy Constructor
	MSArray(const MSArray& other)
		: _size(other.size()), _arrayPtr(new value_type[other.size()])
	{
		for (std::size_t i = 0; i < _size; ++i)
		{
			_arrayPtr[i] = other[i];
		}
	}
	//	Move Constructor
	MSArray(MSArray&& other) noexcept
		: _size(other.size()), _arrayPtr(new value_type[other.size()])
	{
		for (std::size_t i = 0; i < _size; ++i)
		{
			_arrayPtr[i] = other[i];
		}
		other._arrayPtr = new value_type[_size];
		other._size = _size;
	}
	//	Copy Assignment Operator
	MSArray& operator=(const MSArray& other)
	{
		MSArray copy_of_other(other);
		mswap(copy_of_other);
		return *this;
	}
	//	Move Assignment Operator
	MSArray& operator=(MSArray&& other) noexcept
	{
		mswap(other);
		return *this;
	}

public:
	/*
		Bracket Operator
		Return value at index
		Pre:
			0 < index < _size - 1
	*/
	value_type& operator[](std::size_t index) 
	{ 
		return _arrayPtr[index]; 
	}
	/*
		Member Function Begin
		Return Address of First Item In Array
	*/
	value_type* begin() 
	{ 
		return _arrayPtr; 
	}
	/*
		Member Function End
		Return Address of Item One Past Last Item In Array
	*/
	value_type* end() 
	{ 
		return (_arrayPtr + _size); 
	}

	const std::size_t size() const { return _size; }
	const value_type& operator[](std::size_t index) const { return _arrayPtr[index]; }
	const value_type* begin() const { return _arrayPtr; }
	const value_type* end() const { return (_arrayPtr + _size); }
	
private:
	void mswap(MSArray& other) noexcept
	{
		std::swap(_arrayPtr, other._arrayPtr);
		std::swap(_size, other._size);
	}
	value_type* _arrayPtr;
	size_type _size;
};

template<typename T>
bool operator==(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	for (std::size_t i = 0; i < lhs.size(); ++i)
	{
		if (rhs[i]==lhs[i])
		{
			return false;
		}
	}
	return true;
}
template<typename T>
bool operator!=(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	return !(lhs==rhs);
}
template<typename T>
bool operator<(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	for (std::size_t i = 0; i < lhs.size() && i < rhs.size(); ++i)
	{
		if (!(lhs[i] < rhs[i]))
		{
			continue;
		}
		return lhs[i] < rhs[i];
	}
	return lhs.size() < rhs.size();
}
template<typename T>
bool operator>(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	for (std::size_t i = 0; i < lhs.size() && i < rhs.size(); ++i)
	{
		if (lhs[i] < rhs[i])
		{
			continue;
		}
		return !(lhs[i] < rhs[i]);
	}
	return lhs.size() > rhs.size();
}
template<typename T>
bool operator<=(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	return lhs < rhs || lhs == rhs;
}
template<typename T>
bool operator>=(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	return lhs > rhs || lhs == rhs;
}
#endif