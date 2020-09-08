/*
productorder.h
Millard A. Arnold V
Started: 2020-09-03
Updated: 2020-09-08

For CS 311 - Project 1
Source file for ProductOrder class
*/

#include "productorder.h"
#include <ostream>

/*
	Class ProductOrder - Definitions of member functions
*/

/*
	ProductOrder::ProductOrder
	Given name & quantity
	(see header for docs)
*/
ProductOrder::ProductOrder(std::string name, int inventory)
	: _name(name), _quantity(inventory)
{
}

/*
	ProductOrder::getName
	(see header for docs)
*/
std::string ProductOrder::getName() const
{
	return _name;
}

/*
	ProductOrder::getNumber
	(see header for docs)
*/
int ProductOrder::getNumber() const
{
	return _quantity;
}

/*
	ProductOrder::setName
	(see header for docs)
*/
void ProductOrder::setName(std::string name)
{
	_name = name;
}

/*
	ProductOrder::setNumber
	(see header for docs)
*/
void ProductOrder::setNumber(int inventory)
{
	_quantity = inventory;
}

/*
	ProductOrder::empty
	(see header for docs)
*/
bool ProductOrder::empty() const
{
	return _quantity==0;
}

/*
	ProductOrder::toString
	(see header for docs)
*/
std::string ProductOrder::toString() const
{
	return _name + " (" + std::to_string(_quantity) + ")";
}

/*
	ProductOrder::op==
	(see header for docs)
*/
bool ProductOrder::operator==(const ProductOrder& other) const
{
	return _name==other.getName() && _quantity==other.getNumber();
}

/*
	ProductOrder::op!=
	(see header for docs)
*/
bool ProductOrder::operator!=(const ProductOrder& other) const
{
	return !(_name == other.getName() && _quantity == other.getNumber());
}

/*
	ProductOrder::op++ [pre]
	(see header for docs)
*/
ProductOrder& ProductOrder::operator++()
{
	++_quantity;
	return *this;
}

/*
	ProductOrder::op++ [post]
	(see header for docs)
*/
ProductOrder ProductOrder::operator++(int dummy)
{
	auto save = *this;
	++(*this);
	return save;
}

/*
	ProductOrder::op-- [pre]
	(see header for docs)
*/
ProductOrder& ProductOrder::operator--()
{
	--_quantity;
	if (_quantity < 0) _quantity = 0;
	return *this;
}

/*
	ProductOrder::op-- [post]
	(see header for docs)
*/
ProductOrder ProductOrder::operator--(int dummy)
{
	auto save = *this;
	--(*this);
	return save;
}

/*
	op<< (ostream, ProductOrder)
	(see header for docs)
*/
std::ostream& operator<<(std::ostream& out, const ProductOrder& p)
{
	return out << p.toString();
}
