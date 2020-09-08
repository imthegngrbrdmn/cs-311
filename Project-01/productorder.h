//productorder.h
//Millard A. Arnold V
//Started: 2020-09-03
//Updated: 2020-09-07
//
//For CS 311 - Project 1
//Header for ProductOrder class

#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include <string>
#include <ostream>

class ProductOrder
{
public:
	ProductOrder()
		:_name("UNSPECIFIED"),_numItems(0)
	{}
	~ProductOrder()=default;
	ProductOrder(const ProductOrder& other)=default;
	ProductOrder(ProductOrder&& other)=default;
	ProductOrder& operator=(const ProductOrder& other)=default;
	ProductOrder& operator=(ProductOrder&& other)=default;

	ProductOrder(std::string name, int inventory);
	std::string getName() const;
	int getNumber() const;

	void setName(std::string name);
	void setNumber(int inventory);

	bool empty() const;

	std::string toString() const;

	bool operator==(const ProductOrder& other) const;
	bool operator!=(const ProductOrder& other) const;

	ProductOrder& operator++();
	ProductOrder operator++([[maybe_unused]] int dummy);

	ProductOrder& operator--();
	ProductOrder operator--([[maybe_unused]] int dummy);
private:
	std::string _name;
	int _numItems;
};

std::ostream & operator<<(std::ostream & out, const ProductOrder & p);

#endif
