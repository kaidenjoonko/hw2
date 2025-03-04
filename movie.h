#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <string>
#include <set>

class Movie : public Product{
  public:
  //constructor
  Movie(const std::string& name, double price, int qty, const std::string& genre, const std::string& rating);

  //destructor
  ~Movie();

  //set of keywords
  std::set<std::string> keywords() const override;
  std::string displayString() const override;
  void dump(std::ostream& os) const override;

  private:
    std::string genre_;
    std::string rating_;
};

#endif


