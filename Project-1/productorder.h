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
  ProductOrder(const ProductOrder & other);
  ProductOrder(&&ProductOrder other);
  ProductOrder& operator=(const ProductOrder& other);
  ProductOrder& operator=(ProductOrder&& other);

  ProductOrder(std::string name, int inventory);
  std::string getName();
  int getNumber();

  void setName(std::string name);
  void setNumber(int inventory);

  bool empty();

  std::string toString();

  bool operator==(const ProductOrder & other);
  bool operator!=(const ProductOrder & other);
  
  ProductOrder & operator++();
  ProductOrder & operator++([[maybe_unused]] int dummy);

  ProductOrder & operator--();
  ProductOrder & operator--([[maybe_unused]] int dummy);
private:
  std::string _name;
  std::uint_fast64_t _numItems;
}

std::ostream & operator<<(std::ostream & out, const ProductOrder & p);

#endif
