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

#include <algorithm>	// For std::copy and std::swap.
#include <cstddef>		// For std::size_t 

/*
	Template parameter types must have a default constructor.
*/
template<typename T> 
/*
	Class MSArray
	Creates a moderately smart array that will be 
	passed a value type to be held in the array.
	
	Invariants: 
		_size >= 0
		_arrayPtr assigned
		value_type has a default constructor.
*/
class MSArray
{

//	Member Types
public:
	
	//	The type of each item in the array
	using value_type = T;
	
	//	The type of size for the array & the type for index values.
	using size_type = std::size_t;


//	Ctors
public:
	
	/*
		Default ctor
		Create MSArray of size 8
		All items should be default constucted
	*/
	MSArray()
		: _size(8), _arrayPtr(new value_type[8])
	{}
	
	/*
		1 Parameter ctor
		Pre: 
			non-negative integer giving number of items in array
		All items should be default constructed
	*/
	explicit MSArray(size_type size)
		: _size(size), _arrayPtr(new value_type[size])
	{}

	/*
		2 Parameter ctor
		Pre: 
			non-negative integer giving number of items in array
		All items should be set to value of second parameter
	*/
	MSArray(size_type size, value_type value)
		: _size(size), _arrayPtr(new value_type[size])
	{
		for (std::size_t i = 0; i < _size; ++i)
		{
			_arrayPtr[i] = value;
		}
	}


//	MSArray: Big Five
public:
	
	/*
		Destructor
		frees _arrayPtr
		Pre:
			_arrayPtr points to some memory
	*/
	~MSArray()
	{
		delete [] _arrayPtr;
	}
	
	/*
		Copy Constructor
		copies other MSArray
		post: 
			other MSArray does not change
	*/
	MSArray(const MSArray& other)
		: _size(other.size()), _arrayPtr(new value_type[other.size()])
	{
		std::copy(other.begin(), other.end(), _arrayPtr);
	}
	
	/*
		Move Constructor
		moves other MSArray data memebers
		Post:
			other._arrayPtr valid
	*/
	MSArray(MSArray&& other) noexcept
		: _size(other._size), _arrayPtr(other._arrayPtr)
	{
		other._arrayPtr = new value_type[0];
		other._size = 0;
	}
	
	/*
		Copy Assignment Operator
		copies other MSArray
		returns reference to new MSArray
		post:
			other MSArray does not change
	*/
	MSArray& operator=(const MSArray& other)
	{
		MSArray copy_of_other(other);
		mswap(copy_of_other);
		return *this;
	}
	/*
		Move Assignment Operator
		swaps values with other MSArray
		returns reference to new MSArray
	*/
	MSArray& operator=(MSArray&& other) noexcept
	{
		mswap(other);
		return *this;
	}


//	MSArray: Non-const Member Functions
public:
	
	/*
		Bracket Operator
		Return reference to value at index
		Pre:
			0 < index < _size - 1
	*/
	value_type& operator[](std::size_t index) 
	{ 
		return _arrayPtr[index]; 
	}

	/*
		Member Function begin
		Return pointer to first item in array
	*/
	value_type* begin() 
	{ 
		return _arrayPtr; 
	}

	/*
		Member Function end
		Return pointer to one past last item in array
	*/
	value_type* end() 
	{ 
		return (_arrayPtr + _size); 
	}


//	MSArray: Const Member Functions
public:
	
	/*
		Member Function size
		return number of items in array
	*/
	const size_type size() const 
	{
		return _size; 
	}
	
	/*
		Member Function const bracket operator
		Return const referencet to value at index
		Pre:
			0 < index < _size - 1
	*/
	const value_type& operator[](size_type index) const 
	{ 
		return _arrayPtr[index]; 
	}
	
	/*
		Member Function const begin
		Return const pointer to first item in array
	*/
	const value_type* begin() const 
	{ 
		return _arrayPtr; 
	}

	/*
		Member Function const end
		Return const pointer to one past last item in array
	*/
	const value_type* end() const
	{ 
		return (_arrayPtr + _size); 
	}


//	MSArray: Private Functions & Data Members
private:
	
	/*
		Private Member Function mswap
		swaps values of this with another MSArray
	*/
	void mswap(MSArray& other) noexcept
	{
		std::swap(_arrayPtr, other._arrayPtr);
		std::swap(_size, other._size);
	}

	//	Pointer to array
	value_type* _arrayPtr;
	
	//	Size of array
	size_type _size;
};


/*
	global operator== for two MSArrays
	pre:
		T must be a value type
		T must have operator == defined
		MSArrays must have the same value type
*/
template<typename T>
bool operator==(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}

	for (std::size_t i = 0; i < lhs.size(); ++i)
	{
		if (!(rhs[i] == lhs[i]))
		{
			return false;
		}
	}
	return true;
}

/*
	global operator!= for two MSArrays
	pre:
		T must be a value type
		T must have operator == defined
		MSArrays must have the same value type
*/
template<typename T>
bool operator!=(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	return !(lhs==rhs);
}

/*
	global operator< for two MSArrays
	pre:
		T must be a value type
		T must have operator < defined
		MSArrays must have the same value type
*/
template<typename T>
bool operator<(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	for (std::size_t i = 0; i < lhs.size() && i < rhs.size(); ++i)
	{
		if (rhs[i] < lhs[i])
		{
			return false;
		}

		if (lhs[i] < rhs[i])
		{
			return true;
		}
	}

	return lhs.size() < rhs.size();
}

/*
	global operator> for two MSArrays
	pre:
		T must be a value type
		T must have operator < defined
		MSArrays must have the same value type
*/
template<typename T>
bool operator>(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	return rhs < lhs;
}

/*
	global operator<= for two MSArrays
	pre:
		T must be a value type
		T must have operator < defined
		MSArrays must have the same value type
*/
template<typename T>
bool operator<=(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	return !(rhs < lhs);
}

/*
	global operator>= for two MSArrays
	pre:
		T must be a value type
		T must have operator < defined
		MSArrays must have the same value type
*/
template<typename T>
bool operator>=(const MSArray<T>& lhs, const MSArray<T>& rhs)
{
	return !(lhs < rhs);
}
#endif