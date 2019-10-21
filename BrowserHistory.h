#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include "Websites.hpp"
    // std::next, std::prev

using std::string;



class BrowserHistory {
public:
    BrowserHistory();

    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();

    void readFile(string fileName);

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();

private:
    std::list<Websites> webn; //STL Linked list using a class data type
    std::list<Websites>::iterator n; //STL iterator using a class data type
};

BrowserHistory::BrowserHistory(){ //default constructor
  Websites temp; //Creating a temporary class of “Websites”
  webn.push_back(temp); //pushes back a new node with the class
  n = webn.begin(); //pushes back an empty string to give the Linked List size of 1
}

void BrowserHistory::visitSite(string url, size_t filesize){
    size_t counter = 1; //a size counter of 1 to indicate the position of the iterator at one
    size_t holder= webn.size(); //holder to hold the size of the Linked list
    for(std::list<Websites> :: iterator i = webn.begin(); i->Websites_name!=n->Websites_name;++i){ //a for loop to find the potion of the iterator n
      counter++; //incrementing the counter for each loop
    }
    if(counter < holder){ //if the position of the iterator is less than the size
    for(size_t i = counter; i < holder;i++){ //a loop to remove the last node of the Linked List until it reaches the iterator position
    webn.pop_back();
  }
  Websites temp; //Creating a temporary class of “Websites”
  temp.Websites_name = url; //adding the website ulr in the class string variable
  temp.size = filesize; //adding the size in the class size_t variable
  webn.push_back(temp); //pushes back a new node with the class
  ++n; //increment the current position
}

  else if(n->Websites_name==""){ //if the iterator postion class has the empty string and index
    Websites temp; //Creating a temporary class of “Websites”
    temp.Websites_name = url; //adding the website ulr in the class string variable
    temp.size = filesize; //adding the size in the class size_t variable
    webn.push_back(temp); //pushes back a new node with the temporary class
    webn.pop_front(); //webs.pop_front();
    n = webn.begin(); //sets the iterator to the beginning of the Link List
  }
  else { //standard movement of adding a website if the other conditions fail
Websites temp; //Creating a temporary class of “Websites”
temp.Websites_name = url; //adding the website ulr in the class string variable
temp.size = filesize; //adding the size in the class size_t variable
webn.push_back(temp); //pushes back a new node with the temporary class
++n;//increment the current position
}
}

void BrowserHistory::backButton(){ //movement of the iterator to the previous node
  if(n->Websites_name == webn.front().Websites_name) return; //if the iterator is at the beginning of the Link List, it does not move and stays
  --n;//decrement the position in the Linked List
}

void BrowserHistory::forwardButton(){//movment of the iterator to the next node
  if(n->Websites_name == webn.back().Websites_name) return;//if the iterator is at the end of the Link List, it does not move and stays
  ++n;//increment the position in the Linked List
}

void BrowserHistory::readFile(string fileName){
std::ifstream myfile(fileName); //creates an object that reads in the files
string holder1; //a string to hold in websites or actions from the files
size_t holder2; //a size_t to hold in the index from the files
while(myfile >> holder1){ //a loop to go through all the files information as to its sequential
  if(holder1 =="visit"){ //if the file text is telling an action to visit
    myfile >> holder1; //contains the website from the files
    myfile >> holder2; //contains the index from the files
    visitSite(holder1, holder2); //visit the site of the provided information from the files
  }
  else if(holder1=="back"){ //if the file text is telling to move back a website
    backButton(); //calls the function that moves back the iterator to the previous node
  }
  else{
    forwardButton(); //calls the function that moves the iterator forward to the next node
  }
}
}

string BrowserHistory::currentUrl(){
if(webn.empty()) return ""; //if the Linked list of the string is empty, returns an empty string
  return n->Websites_name; //if not, return the current website of the iterator position
}

size_t BrowserHistory::currentPageSize(){
  if(webn.empty()) return 0; //if the Linked list is empty, returns 0
  return n->size; //returns the size of the website from the iterator position
}

  size_t BrowserHistory::getHistoryLength(){
     return webn.size(); //gives out the length of the Linked List
  }
