#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include <string>
#include <cstdint>

class ProductOrder
{
public:
  ProductOrder();
  ~ProductOrder();
  ProductOrder(const &ProductOrder other);
  ProductOrder(&&ProductOrder other);
  ProductOrder& operator=(const ProductOrder& other);
  ProductOrder& operator=(ProductOrder&& other);
private:
  std::string _name;
  std::uint_fast64_t _numItems;
}

#endif
