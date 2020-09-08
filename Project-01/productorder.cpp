#include "productorder.h"

ProductOrder::ProductOrder(std::string name, int inventory)
	: _name(name), _quantity(inventory)
{
}

std::string ProductOrder::getName() const
{
	return _name;
}

int ProductOrder::getNumber() const
{
	return _quantity;
}

void ProductOrder::setName(std::string name)
{
	_name = name;
}

void ProductOrder::setNumber(int inventory)
{
	_quantity = inventory;
}

bool ProductOrder::empty() const
{
	return _quantity==0;
}

std::string ProductOrder::toString() const
{
	return _name + " (" + std::to_string(_quantity) + ")";
}

bool ProductOrder::operator==(const ProductOrder& other) const
{
	return _name==other.getName() && _quantity==other.getNumber();
}

bool ProductOrder::operator!=(const ProductOrder& other) const
{
	return !(_name == other.getName() && _quantity == other.getNumber());
}

ProductOrder& ProductOrder::operator++()
{
	++_quantity;
	return *this;
}

ProductOrder ProductOrder::operator++(int dummy)
{
	auto save = *this;
	++(*this);
	return save;
}

ProductOrder& ProductOrder::operator--()
{
	--_quantity;
	if (_quantity < 0) _quantity = 0;
	return *this;
}

ProductOrder ProductOrder::operator--(int dummy)
{
	auto save = *this;
	--(*this);
	return save;
}

std::ostream& operator<<(std::ostream& out, const ProductOrder& p)
{
	return out << p.toString();
}
