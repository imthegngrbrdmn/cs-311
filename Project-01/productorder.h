/*
productorder.h
Millard A. Arnold V
Started: 2020-09-03
Updated: 2020-09-07

For CS 311 - Project 1
Header file for ProductOrder class
*/

#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include <string>
#include <ostream>

/*
	class ProductOrder - Class Definition

	ProductOrder: name, quantity ordered.
	Invariants: _quantity >=0
*/

class ProductOrder
{

//	ProductOrder: ctors, dctor, op=
public:

	/*
		Default ctor
		Set name to UNSPECIFIED
		Set quantity to 0
	*/
	ProductOrder()
		:_name("UNSPECIFIED"),_quantity(0)
	{}

	/*
		ctor given name & quantity
		set name to given name
		set quantity to given quantity
		Pre:
			inventory>0
	*/
	ProductOrder(std::string name, int inventory);
	
	//	Big 5: automatically generated versions
	~ProductOrder()=default;
	ProductOrder(const ProductOrder& other)=default;
	ProductOrder(ProductOrder&& other)=default;
	ProductOrder& operator=(const ProductOrder& other)=default;
	ProductOrder& operator=(ProductOrder&& other)=default;

//	ProductOrder: general public functions
public:
	/*
		getName
		return name of product
	*/
	std::string getName() const;

	/*
		getNumber
		return number of product
	*/
	int getNumber() const;

	/*
		setName
		set product name to given name
	*/
	void setName(std::string name);

	/*
		setNumber
		set product quantity to given quantity
	*/
	void setNumber(int inventory);

	/*
		empty
		return true if the quantity is 0
	*/
	bool empty() const;

	/*
		toString
		return a string representation of ProductOrder
		post:
			"_name (_quantity)"
	*/
	std::string toString() const;

//	ProductOrder: general public operators
public:
	/*
		op==
		return true if name and quantity are equal
	*/
	bool operator==(const ProductOrder& other) const;

	/*
		op!=
		return true if name and quantity are different
	*/
	bool operator!=(const ProductOrder& other) const;

	/*
		op++ [pre]
		add one to quantity
		return new object
	*/
	ProductOrder& operator++();

	/*
		op++ [post]
		add one to quantity
		return copy of old object
	*/
	ProductOrder operator++([[maybe_unused]] int dummy);

	/*
		op-- [pre]
		subtract one from quantity
		return new object
	*/
	ProductOrder& operator--();

	/*
		op-- [post]
		subtract one from quantity
		return copy of old object
		*/
	ProductOrder operator--([[maybe_unused]] int dummy);

//	ProductOrder: Data members
private:

	std::string _name;	// Name of product
	int _quantity;		// Quantity of product

};	//End class ProductOrder

/*
	operator<< (ostream, ProductOrder)
	Prints given ProductOrder object as converted by toString
*/
std::ostream & operator<<(std::ostream & out, const ProductOrder & p);

#endif
