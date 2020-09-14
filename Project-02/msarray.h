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

template<class T>
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
	MSArray<value_type>()
		: _arrayPtr(new value_type(8))
	{

	}
	
	/*
		1 Parameter ctor
		Pre: 
			non-negative integer giving number of items in array
		All items should be default constructed
	*/
	explicit MSArray<value_type>(int size)
		: _size(size), _arrayPtr(new value_type(size))
	{

	}

	/*
		2 Parameter ctor
		Pre: 
			non-negative integer giving number of items in array
		All items should be set to value of second parameter
	*/
	MSArray<value_type>(int size, value_type value)
		: _size(size), _arrayPtr(new value_type(size))
	{

	}

	//	Big 5
	~MSArray()
	{
		delete(_arrayPtr);
	}
	MSArray(const MSArray& other)
		: _size(other.size()), _arrayPtr(new value_type(other.size()))
	{
		std::copy(other.begin(), other.end(), _arrayPtr);
	}
	MSArray(MSArray&& other) noexcept
		: _size(other.size()), _arrayPtr(new value_type(other.size()))
	{
		std::move(other.begin(), other.end(), _arrayPtr);
	}
	MSArray& operator=(const MSArray& other)	//copy
	{
		MSArray copy_of_other(other);
		swap(other);
		return *this;
	}
	MSArray& operator=(MSArray&& other) noexcept	//move
	{
		swap(other);
		return *this;
	}

public:
	value_type& operator[](std::size_t index) { return _arrayPtr[index]; }
	value_type* begin() { return _arrayPtr; }
	value_type* end() { return begin() + _size; }

	const std::size_t size() const { return _size; }
	const value_type& operator[](std::size_t index) const { return _arrayPtr[index]; }
	const value_type* begin() const { return begin(); }
	const value_type* end() const { return end(); }
	const bool operator==(const MSArray& other) const 
	{
		//if (value_type != other.value_type) throw std::invalid_argument("Cannot compare MSArray of different types");
		return _size == other.size(); 
	}
	const bool operator!=(const MSArray& other) const 
	{
		//if (value_type != other.value_type) throw std::invalid_argument("Cannot compare MSArray of different types");
		return _size != other.size(); 
	}
	const bool operator<(const MSArray& other) const
	{
		if (value_type != other::value_type) throw std::invalid_argument("Cannot compare MSArray of different types");
		for (std::size_t i = 0; i < _size && i < other.size(); ++i)
		{
			if (*this[i] == other[i])
			{
				continue;
			}
			return *this[i] < other[i];
		}
		return _size < other.size();
	}
	const bool operator>(const MSArray& other) const
	{
		//if (value_type != other::value_type) throw std::invalid_argument("Cannot compare MSArray of different types");
		for (std::size_t i = 0; i < _size && i < other.size(); ++i)
		{
			if (*this[i] == other[i])
			{
				continue;
			}
			return *this[i] > other[i];
		}
		return _size > other.size();
	}
	const bool operator<=(const MSArray& other) const
	{
		return *this == other || *this < other;
	}
	const bool operator>=(const MSArray& other) const
	{
		return *this == other || *this > other;
	}
private:
	void swap(MSArray& other) noexcept
	{
		std::swap(_arrayPtr, other._arrayPtr);
		std::swap(_size, other._arrayPtr);
	}
	value_type* _arrayPtr;
	std::size_t _size;
};

#endif