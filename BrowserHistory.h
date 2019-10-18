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
    std::list<string> webn; //SLL Linked list using a string data type
    std::list<string> :: iterator n; //SLL iterator using a string data type
    std::list<size_t> webs;//SLL Linked list using an size_t data type
    std::list<size_t> :: iterator s;//SLL iteratort using an size_t data type
  // TO BE COMPLETED
};

BrowserHistory::BrowserHistory(){ //default constructor
webn.push_back(""); //pushes back an empty string to give the Linked List a size of 1
webs.push_back(0); //pushes an emty integer to give the Linked List a size of 1
n = webn.begin(); //gives the iterator a starting point which now points to the first node of the Linked List
s = webs.begin(); //gives the iterator a starting point which now points to the first node of the Linked List
}

void BrowserHistory::visitSite(string url, size_t filesize){
    size_t counter = 1; //a size counter of 1 to inidcate the postion of the iterator at one
    size_t holder= webn.size(); //holder to hold the size of the Linked list
    for(std::list<string> :: iterator i = webn.begin(); *i!=*n;++i){ //a for loop to find the potion of the iterator n which correpsonds to itertaor s
      counter++; //incrementing the counter for each loop
    }
    if(counter < holder){ //if the postion of the iterator is less than the size
    for(size_t i = counter; i < holder;i++){ //a loop to remove the last node of both Linked List until it reaches the iterator postion
    webn.pop_back();
    webs.pop_back();
  }
  webn.push_back(url); //pushes back a new node with the webiste name
  ++n; //increment the current postion
  webs.push_back(filesize); //pushes back a new node with the index of the webiste
  ++s;//increment the postion in the Linked List
}

  else if(*n==""){ //if the iterator value is the empty string and index
    webn.push_back(url); //pushes back a new node with the webiste name
    webs.push_back(filesize);//pushes back a new node with the index of the webiste
    webn.pop_front();
    webs.pop_front();
    n = webn.begin();//sets the iterator to the begining of the Link List for the string
    s = webs.begin();//sets the iterator to the begining of the Link List for the size_t
  }
  else { //standard movment of adding a webiste when the other conditions fails
webn.push_back(url); //pushes back a new node with the index of the webiste
++n;//increment the current postion
webs.push_back(filesize);//pushes back a new node with the index of the webiste
++s;//increment the postion in the Linked List
}
}

void BrowserHistory::backButton(){ //movment of the iterator to the previuse node

  if(*n == webn.front()) return; //if the itertaor is at the begining of the Link List, it does not move and stays
  --n;//decrement the postion in the Linked List
  --s;//decrement the postion in the Linked List
}

void BrowserHistory::forwardButton(){//movment of the iterator to the next node
  if(*n == webn.back()) return;//if the itertaor is at the end of the Link List, it does not move and stays
  ++n;//increment the postion in the Linked List
  ++s;//increment the postion in the Linked List
}

void BrowserHistory::readFile(string fileName){
std::ifstream myfile(fileName); //creates an object that reads in the files
string holder1; //a string to hold in websites or actions from the files
size_t holder2; //a size_t to hold in the index from the files
while(myfile >> holder1){ //a loop to go through all the files information as its sequential
  myfile.ignore(); //to remove any potential empty spaces
  if(holder1 =="visit"){ //if the file text is telling an action to visit
    myfile >> holder1; //contains the website from the files
    myfile.ignore(); //to remove any potential empty spaces
    myfile >> holder2; //contains the index from the files
    myfile.ignore();//to remove any potential empty spaces
    visitSite(holder1, holder2); //visit the site of the provided information from the files
  }
  else if(holder1=="back"){ //if the file text is telling to move back a webiste
    backButton(); //calls the fucntion that moves back the itertaor to the previuse node
  }
  else{
    forwardButton(); //calls the fucntion that moves the itertaor foeard to the next node
  }
}
}

string BrowserHistory::currentUrl(){
if(webn.empty()) return ""; //if the Linked list of the string is empty, retruns an empty string
  return *n; //if not, return the current webiste of the iterator postion
}

size_t BrowserHistory::currentPageSize(){
  if(webs.empty()) return 0; //if the Linked list of size_t is empty, retruns 0
  return *s; //returns the index of the webiste from the iterator postion
}

  size_t BrowserHistory::getHistoryLength(){
     return webn.size(); //gives out the lenght of the Linked List
  }
