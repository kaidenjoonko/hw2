#include <sstream>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string& name, double price, int qty, const std::string& isbn, const std::string& author)
 : Product("book", name, price, qty), isbn_(isbn), author_(author){}

Book::~Book(){}

//keywords() which returns the appropriate keywords to index the product
std::set<std::string> Book::keywords() const{

  std::string lowerName = convToLower(name_);
  std::string lowerAuthor = convToLower(author_);

  //1. create set of keywords
  std::set<std::string> nameKeywords = parseStringToWords(lowerName);
  std::set<std::string> authorKeywords = parseStringToWords(lowerAuthor);

  nameKeywords.insert(authorKeywords.begin(), authorKeywords.end());

  nameKeywords.insert(isbn_);

  return nameKeywords;
}

//displayString() [to create a string that contains the product info]
std::string Book::displayString() const
{
  std::string result = name_ + "\n";
  result += "Author: " + author_ + " ISBN: " + isbn_ + "\n";
  result += std::to_string(price_) + " " + std::to_string(qty_) + " left.";

  return result;
}

//dump() [that outputs the database format of the product info]
void Book::dump(std::ostream& os) const
{
  Product::dump(os);
    os << isbn_ << "\n" << author_ << std::endl;
}