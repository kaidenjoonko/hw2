#ifndef BOOK_H
#define BOOK_H
#include "product.h" //include base class
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Book : public Product{
  public:
    //constructor
    Book(const std::string& name, double price, int qty, const std::string& isbn, const std::string& author);


    //destructor
    ~Book();

    //override functions
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

  private: 
    std::string isbn_;
    std::string author_;
};
#endif