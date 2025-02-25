#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include <string>
#include <set>

class Clothing : public Product{
  public:
  //constructor
  Clothing(const std::string& name, double price, int qty, const std::string& size, const std::string& brand);

  //destructor
  ~Clothing();

  //set of keywords
  std::set<std::string> keywords() const;
  std::string displayString() const;
  void dump(std::ostream& os) const;

  private:
    std::string size_;
    std::string brand_;
};

#endif


