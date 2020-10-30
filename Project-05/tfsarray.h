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
#include<stdexcept>

//	T must have a default ctor and big 5
template<typename T>
/*
	class TFSArray
	efficient resizable and exception-safe array.
	Invariants: _data is owned by this
*/
class TFSArray
{
//	public member types
public:
	//	The type of each item in the array
	using value_type = T;
	
	//	The type of the size of an array and an index into an array
	using size_type = std::size_t;

	//	The type of a random-access iterator that allows modification of the item it references
	using iterator = value_type*;

	// The type of a random-access iterator that does not allow modification of the item it references
	using const_iterator = const value_type*;


//	private constants
private:
	//	The default capacity of an array
	enum { DEFAULT_CAP = 16 };

//	ctors and big 5
public:
	/*
		Default Ctor creates a TFSArray of size zero
		Ctor from size creates a TFSArray of given size

		Basic Guarantee
		Exception Neutral
	*/
	explicit TFSArray(size_type size = 0)
		: _size(size), 
		_capacity(std::max(size, size_type(DEFAULT_CAP))),
		_data(new value_type[_capacity])
	{}

	/*
		Dctor

		No Throw Guarantee
		Exception Neutral
	*/
	~TFSArray()
	{
		delete[] _data;
	}
	
	/*
		Copy ctor

		Strong Guarantee
		Exception Neutral
	*/
	TFSArray(const TFSArray& other)
	{
		operator=(other);
	}
	
	/*
		Move ctor

		No Throw Guarantee
		Exception Neutral
	*/
	TFSArray(TFSArray&& other) noexcept
	{
		swap(other);
		other._size = 0;
		other._capacity = 0;
	}
	
	/*
		Copy Assignment operator

		Strong Guarantee
		Exception Neutral
	*/
	TFSArray& operator=(const TFSArray& other)
	{
		value_type* temp = new value_type[other.size()];
		try
		{
			std::copy(other.begin(), other.end(), temp);
		}
		catch (...)
		{
			delete[] temp;
			_size = 0;
			_capacity = 0;
			throw;
		}
		_capacity = other.size();
		_size = _capacity;
		std::swap(_data, temp);
		delete[] temp;
		return *this;
	}
	/*
		Move Assignment operator
	
		No Throw Guarantee
		Exception Neutral
	*/
	TFSArray& operator=(TFSArray&& other) noexcept
	{
		swap(other);
		other._size = 0;
		other._capacity = 0;
		return *this;
	}


//	Public Member Functions
public:
	/*
		Bracket Operator
		Returns data at index

		Strong Guarantee
		Throws std::out_of_range
		pre: index < size()
	*/
	value_type& operator[](size_type index)
	{
		if (index < size())
		{
			return _data[index];
		}
		throw std::out_of_range("out of range");
	}
	/*
		const Bracket Operator
		Returns data at index

		Strong Guarantee
		Throws std::out_of_range
		pre: index < size()
	*/
	const value_type& operator[](size_type index) const
	{
		if (index < size())
		{
			return _data[index];
		}
		throw std::out_of_range("out of range");
	}

	/*
		size member function
		returns size of array
		
		No Throw Guarantee
		Exception Neutral
	*/
	size_type size() noexcept
	{
		return _size;
	}

	/*
		size const member function
		returns size of array

		No Throw Guarantee
		Exception Neutral
	*/
	const size_type size() const noexcept
	{
		return _size;
	}

	/*
		empty member function
		returns true if size is zero
		
		No Throw Guarantee
		Exception Neutral
	*/
	bool empty() noexcept
	{
		return size() == 0;
	}

	/*
		empty const member function
		returns true if size is zero

		No Throw Guarantee
		Exception Neutral
	*/
	const bool empty() const noexcept
	{
		return size() == 0;
	}

	/*
		resize member function
		resizes array to new size
		
		Strong Guarantee
		Exception Neutral
	*/
	void resize(size_type size)
	{
		if (size <= _size)
		{
			_size = size;
		}
		else
		{
			if (size > _capacity)
			{
				size_type new_cap = std::max(2 * _capacity, size);
				iterator temp = new value_type[new_cap];
				try 
				{
					std::copy(begin(), end(), temp);
				}
				catch (...)
				{
					delete[] temp;
					throw;
				}
				std::swap(temp, _data);
				delete[] temp;
				_capacity = new_cap;
				_size = size;
			}
			else
			{
				std::fill(_data + _size, _data + size, value_type());
				_size = size;
			}
		}
	}
	/*
		Insert member function
		Inserts value just before item referenced by given iterator
		returns iterator to inserted value

		Strong Guarantee
		Throws std::out_of_range
		pre: iterator is in the range of the array
	*/
	iterator insert(const iterator& it, const value_type& val)
	{
		if (it > end() || it < begin())
		{
			throw std::out_of_range("INSERT iterator out of range");
		}
		size_type index = it - begin();
		resize(size() + 1);
		_data[_size-1] = val;
		std::rotate(begin()+index, end() - 1, end());
		return begin() + index;
	}

	/*
		erase member function
		Removes vlaue referenced by given iterator
		returns iterator to item just after the removed item
		
		Strong Guarantee
		Throws std::out_of_range 
		pre: iterator is in the range of the array
	*/
	iterator erase(const iterator& it)
	{
		if (it > end() || it < begin())
		{
			throw std::out_of_range("ERASE iterator out of range");
		}
		if (it == end())
		{
			resize(size() - 1);
			return end();
		}
		size_type index = it - begin();
		std::rotate(it, it + 1, end());
		resize(size() - 1);
		return index+begin();
	}

	/*
		begin member function
		returns iterator to first item in array
		
		No Throw Guarantee
		Exception Neutral
	*/
	iterator begin() noexcept
	{
		return _data;
	}
	
	/*
		begin const member function
		returns iterator to first item in array
		
		No Throw Guarantee
		Exception Neutral
	*/
	const_iterator begin() const noexcept
	{
		return _data;
	}

	/*
		end member function
		returns iterator to one past last item in array

		No Throw Guarantee
		Exception Neutral
	*/
	iterator end() noexcept
	{
		return (_data + _size);
	}
	
	/*
		end const member function
		returns iterator to one past last item in array

		No Throw Guarantee
		Exception Neutral
	*/
	const_iterator end() const noexcept
	{
		return (_data + _size);
	}


	/*
		push_back member function
		adds item to end of array
		
		Strong Guarantee
		Exception Neutral
	*/
	void push_back(const value_type& item)
	{
		insert(end(), item);
	}

	/*
		pop_back member function
		removes item from end of array
		
		Strong Guarantee
		Exception Neutral
	*/
	void pop_back()
	{
		if (_size > 0)
		{
			erase(end());
		}
	}
	
	/*
		swap member function
		swaps values of this and given array

		No Throw Guarantee
		Exception Neutral
	*/
	void swap(TFSArray& other) noexcept
	{
		if (&other == this) return;
		std::swap(_data, other._data);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
	}


//	Private Data Members
private:
	size_type _capacity;	// size of the allocated memory
	value_type* _data;		// Pointer to first item in array
	size_type _size;		// Size of the array
};
#endif