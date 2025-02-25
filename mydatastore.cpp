#include "mydatastore.h"
#include "util.h"
#include <iostream>
#include <fstream>

MyDataStore::MyDataStore() { }

MyDataStore::~MyDataStore() { }

void MyDataStore::addProduct(Product* product){
  products_.push_back(product);

  //get keywords
  std::set<std::string>keywords = product->keywords();

  //associate keywords
  std::set<std::string>::iterator it;
  for(it = keywords.begin(); it!=keywords.end(); ++it){
    keywordMap_[*it].insert(product);
  }
}

void MyDataStore::addUser(User* user){
  users_[user->getName()] = user;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  //create result set 
  std::set<Product*> resultSet;

  //go thorugh terms
  for(size_t i=0; i<terms.size(); i++){
    std::string term = convToLower(terms[i]);
    if(keywordMap_.find(term) != keywordMap_.end()){
      //1st run thorugh
      if(resultSet.empty()){
        resultSet = keywordMap_[term];
      }
      else{
        if(type == 1){
          resultSet = setUnion(resultSet, keywordMap_[term]);
        }else{
          resultSet = setIntersection(resultSet, keywordMap_[term]);
        }
      }
    }
  }

  //convert to a vector to return 
  return std::vector<Product*>(resultSet.begin(), resultSet.end());
}

void MyDataStore::addToCart(const std::string& username, Product* product) {
  if(users_.find(username) == users_.end()){
    std::cout << "Invalid request" << std::endl;
  }
  else{
    userCart_[username].push_back(product);
  }
}


void MyDataStore::viewCart(const std::string& username) {
   // search for the user name and fails
   if(users_.find(username) == users_.end()){
    std::cout << "Invalid username\n";
    return;
   }
   //access user's cart otherwise
   std::vector<Product*> cart = userCart_[username];
   for(size_t i=0; i < cart.size(); i++){
      std::cout << "Item " << i+1 << "\n" << cart[i]->displayString() << std::endl;
   }
}


void MyDataStore::buyCart(const std::string& username) {
  //search for username and fails
  if(users_.find(username) == users_.end()){
    std::cout << "Invalid username\n";
    return;
  }

  //access user's cart to buy
  std::vector<Product*>& cart = userCart_[username];
  std::vector<Product*> newCart;

  for(size_t i = 0; i < cart.size(); i++){
    Product* p = cart[i];
    //check if 1)item is available  2) user has enough money
    if(p->getQty() > 0 && users_[username]->getBalance() >= p->getPrice()){
      //1)change item inventory count
      p->subtractQty(1);
      //2)update user balance
      users_[username]->deductAmount(p->getPrice());
    }else{
      //keep item in cart
      newCart.push_back(p);
    }
  }
  //update user's cart
  userCart_[username]= newCart;
}


void MyDataStore::dump(std::ostream& ofile) {
  ofile << "<products>\n";

  //create iterator it
  std::vector<Product*>::iterator it;
  //loop and dump
  for(it = products_.begin(); it != products_.end(); ++it){
    (*it)->dump(ofile);
  }
  ofile << "</products>\n";

  ofile << "<users>\n";
  for(std::unordered_map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it){
    User* u = it->second;
    u->dump(ofile);
  }
  ofile << "</users>\n";

  //deallocate
  for(size_t i = 0; i < products_.size(); i++){
    delete products_[i];
  }
  for(std::unordered_map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it){
    delete(it->second);
  }
  users_.clear();
}
