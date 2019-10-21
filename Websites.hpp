#pragma once


#include <string>
#include <iterator>
#include <list>
using std::string;

class Websites{ //a website class to hold in the URL and the size
public:
  string Websites_name; //string variable size for URL
  size_t size; //size_t to hold the website size
  Websites():Websites_name(""),size(0){} //default constructor
};
