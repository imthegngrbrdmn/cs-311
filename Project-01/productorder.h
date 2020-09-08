#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include <string>
#include <cstdint>
#include <ostream>

class ProductOrder
{
public:
	ProductOrder();
	~ProductOrder();
	ProductOrder(const ProductOrder& other);
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
	ProductOrder& operator++([[maybe_unused]] int dummy);

	ProductOrder& operator--();
	ProductOrder& operator--([[maybe_unused]] int dummy);
private:
	std::string _name;
	std::uint_fast32_t _numItems;
};

std::ostream & operator<<(std::ostream & out, const ProductOrder & p);

#endif
