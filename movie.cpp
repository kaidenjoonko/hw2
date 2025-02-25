#include <sstream>
#include "movie.h"
#include "util.h"

Movie::Movie(const std::string& name, double price, int qty, const std::string& genre, const std::string& rating)
 : Product("movie", name, price, qty), genre_(genre), rating_(rating){}

Movie::~Movie(){}

//keywords() which returns the appropriate keywords to index the product
std::set<std::string> Movie::keywords() const{

  std::string lowerName = convToLower(name_);

  //1. create set of keywords
  std::set<std::string> keySet = parseStringToWords(lowerName);

  keySet.insert(convToLower(genre_));

  return keySet;
}

//displayString() [to create a string that contains the product info]
std::string Movie::displayString() const
{
  std::string result = name_ + "\n";
  result += "Genre: " + genre_ + " Rating: " + rating_ + "\n";
  result += std::to_string(price_) + " " + std::to_string(qty_) + " left.";

  return result;
}

//dump() [that outputs the database format of the product info]
void Movie::dump(std::ostream& os) const
{
  Product::dump(os);
  os << genre_ << "\n" << rating_ << std::endl;
}