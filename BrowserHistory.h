#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
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
    std::list<string> webn; //STL Linked list using a string data type
    std::list<string> :: iterator n; //STL iterator using a string data type
    std::list<size_t> webs;//STL Linked list using an size_t data type
    std::list<size_t> :: iterator s;//STL iteratort using an size_t data type
  // TO BE COMPLETED
};

BrowserHistory::BrowserHistory(){ //default constructor
webn.push_back(""); //pushes back an empty string to give the Linked List size of 1
webs.push_back(0); //pushes an empty integer to give the Linked List size of 1
n = webn.begin(); //gives the iterator a starting point which now points to the first node of the Linked List
s = webs.begin(); //gives the iterator a starting point which now points to the first node of the Linked List
}

void BrowserHistory::visitSite(string url, size_t filesize){
    size_t counter = 1; //a size counter of 1 to indicate the position of the iterator at one
    size_t holder= webn.size(); //holder to hold the size of the Linked list
    for(std::list<string> :: iterator i = webn.begin(); *i!=*n;++i){ //a for loop to find the potion of the iterator n which corresponds to iterator s
      counter++; //incrementing the counter for each loop
    }
    if(counter < holder){ //if the position of the iterator is less than the size
    for(size_t i = counter; i < holder;i++){ //a loop to remove the last node of both Linked List until it reaches the iterator position
    webn.pop_back();
    webs.pop_back();
  }
  webn.push_back(url); //pushes back a new node with the website name
  ++n; //increment the current position
  webs.push_back(filesize); //pushes back a new node with the index of the website
  ++s;//increment the position in the Linked List
}

  else if(*n==""){ //if the iterator value is the empty string and index
    webn.push_back(url); //pushes back a new node with the website name
    webs.push_back(filesize);//pushes back a new node with the index of the website
    webn.pop_front();
    webs.pop_front();
    n = webn.begin();//sets the iterator to the beginning of the Link List for the string
    s = webs.begin();//sets the iterator to the beginning of the Link List for the size_t
  }
  else { //standard movement of adding a website when the other conditions fail
webn.push_back(url); //pushes back a new node with the index of the website
++n;//increment the current position
webs.push_back(filesize);//pushes back a new node with the index of the website
++s;//increment the position in the Linked List
}
}

void BrowserHistory::backButton(){ //movement of the iterator to the previous node
  if(*n == webn.front()) return; //if the iterator is at the beginning of the Link List, it does not move and stays
  --n;//decrement the position in the Linked List
  --s;//decrement the position in the Linked List
}

void BrowserHistory::forwardButton(){//movment of the iterator to the next node
  if(*n == webn.back()) return;//if the iterator is at the end of the Link List, it does not move and stays
  ++n;//increment the position in the Linked List
  ++s;//increment the position in the Linked List
}

void BrowserHistory::readFile(string fileName){
std::ifstream myfile(fileName); //creates an object that reads in the files
string holder1; //a string to hold in websites or actions from the files
size_t holder2; //a size_t to hold in the index from the files
while(myfile >> holder1){ //a loop to go through all the files information as to its sequential
  myfile.ignore(); //to remove any potential empty spaces
  if(holder1 =="visit"){ //if the file text is telling an action to visit
    myfile >> holder1; //contains the website from the files
    myfile.ignore(); //to remove any potential empty spaces
    myfile >> holder2; //contains the index from the files
    myfile.ignore();//to remove any potential empty spaces
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
  return *n; //if not, return the current website of the iterator position
}

size_t BrowserHistory::currentPageSize(){
  if(webs.empty()) return 0; //if the Linked list of size_t is empty, returns 0
  return *s; //returns the index of the website from the iterator position
}

  size_t BrowserHistory::getHistoryLength(){
     return webn.size(); //gives out the length of the Linked List  
  }
