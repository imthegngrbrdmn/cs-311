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

#include<cstddef>
#include<algorithm>

template<typename T>
class TFSArray
{
public:
	using value_type = T;
	using size_type = std::size_t;
	using iterator = value_type*;
	using const_iterator = const value_type*;
private:
	enum { DEFAULT_CAP = 16 };
public:
	// Default Ctor
	explicit TFSArray(size_type size = 0)
		: _size(size), 
		_capacity(std::max(_size, size_type(DEFAULT_CAP))), //must be declared before _data
		_data(new value_type[_capacity])
	{}

	// Dctor
	~TFSArray()
	{
		delete[] _data;
	}
	// Copy ctor
	TFSArray(const TFSArray& other)
		: _capacity(other._capacity), 
		_size(other._size), 
		_data(new value_type[other._capacity])
	{
		std::copy(other.begin(), other.end(), _data);
	}
	// move ctor
	TFSArray(TFSArray&& other) noexcept
		: _size(other._size), 
		_capacity(other._capacity),
		_data(other._data)
	{
		other._data = nullptr;
		other._size = 0;
		other._capacity = 0;
	}
	// copy assignment op
	TFSArray& operator=(const TFSArray& other)
	{
		TFSArray copy_of_other(other);
		mswap(copy_of_other);
		return *this;
	}
	// move assignment op
	TFSArray& operator=(TFSArray&& other) noexcept
	{
		mswap(other);
		return *this;
	}

public:
	// Access value at index
	value_type& operator[](size_type index)
	{
		return _data[index];
	}
	const value_type& operator[](size_type index) const
	{
		return _data[index];
	}

	// Returns size of array
	size_type size() noexcept
	{
		return _size;
	}
	const size_type size() const noexcept
	{
		return _size;
	}

	// True if size is zero
	bool empty() noexcept
	{
		return size() == 0;
	}
	const bool empty() const noexcept
	{
		return size() == 0;
	}

	// Resizes array to given size
	void resize(size_type size)
	{
		if (size < _capacity)
		{
			_size = size;
		}
		else
		{
			TFSArray<value_type> temp(std::max(size, _capacity * 2));
			temp._size = size;
			std::copy(begin(), end(), temp._data);
			mswap(temp);
		}
	}

	// Inserts value just before item referenced by given iterator
	// returns iterator to inserted value
	iterator insert(const iterator& it, const value_type& val)
	{
		size_type index = it - begin();
		resize(size() + 1);
		*(end()-1) = val;
		std::rotate(it, end() - 1, end());
		return begin() + index;
	}

	// Removes value referenced by iterator
	// Returns iterator to item just after removed item
	iterator erase(const iterator& it)
	{
		std::rotate(it - 1, it, end());
		resize(size() - 1);
		return it;
	}

	// Returns iterator to item 0 in array
	iterator begin() noexcept
	{
		return _data;
	}
	const_iterator begin() const noexcept
	{
		return _data;
	}

	// Returns iterator to item one past end of array
	iterator end() noexcept
	{
		return (_data + _size);
	}
	const_iterator end() const noexcept
	{
		return (_data + _size);
	}

	// Adds item to end of the array
	void push_back(const value_type& item)
	{
		insert(end(),item);
	}

	// Removes last item from end of array
	void pop_back()
	{
		erase(end());
	}

	// Swaps the values of *this and given array
	void swap(TFSArray& other) noexcept
	{
		mswap(other);
	}
private:
	void mswap(TFSArray& other) noexcept
	{
		std::swap(_data, other._data);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
	}
private:
	iterator _data;			// Pointer to first item in array
	size_type _size;		// Size of the array
	size_type _capacity;	// size of the allocated memory
};
#endif