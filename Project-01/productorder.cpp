#include "productorder.h"

ProductOrder::ProductOrder()
	:_name("UNSPECIFIED"), _numItems(0)
{
}

ProductOrder::~ProductOrder()
{
	delete(this);
}

ProductOrder::ProductOrder(std::string name, int inventory)
	: _name(name), _numItems(inventory)
{
}

std::string ProductOrder::getName() const
{
	return _name;
}

int ProductOrder::getNumber() const
{
	return _numItems;
}

void ProductOrder::setName(std::string name)
{
	_name = name;
}

void ProductOrder::setNumber(int inventory)
{
	_numItems = inventory;
}

bool ProductOrder::empty() const
{
	return _numItems==0;
}

std::string ProductOrder::toString() const
{
	return _name + " (" + std::to_string(_numItems) + ")";
}

bool ProductOrder::operator==(const ProductOrder& other) const
{
	return _name==other.getName() && _numItems==other.getNumber();
}

bool ProductOrder::operator!=(const ProductOrder& other) const
{
	return !(_name == other.getName() && _numItems == other.getNumber());
}

ProductOrder& ProductOrder::operator++()
{
	++_numItems;
	return *this;
}

ProductOrder& ProductOrder::operator++(int dummy)
{
	auto save = *this;
	++(*this);
	return save;
}

ProductOrder& ProductOrder::operator--()
{
	--_numItems;
	return *this;
}

ProductOrder& ProductOrder::operator--(int dummy)
{
	auto save = *this;
	--(*this);
	return save;
}

std::ostream& operator<<(std::ostream& out, const ProductOrder& p)
{
	return out << p.toString();
}
