#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  //intialize set
  std::set<T> intersectionSet;

  //iterator 
  typename std::set<T>:: iterator it;

  //loop through s1
  for(it = s1.begin(); it != s1.end(); ++it){
    //check if element in s1 is in s2
    if(s2.find(*it) != s2.end()){
      //insert into the set
      intersectionSet.insert(*it);
    }
  }
  //return set
  return intersectionSet;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  //intialize set
  std::set<T> unionSet;

  //iterator 
  typename std::set<T>:: iterator it;

  //loop through s1
  for(it = s1.begin(); it != s1.end(); ++it){
    unionSet.insert(*it);
  }

  //loop through s2
  for(it = s2.begin(); it != s2.end(); ++it){
    unionSet.insert(*it);
  }

  //return set
  return unionSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
