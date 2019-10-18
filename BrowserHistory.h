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
    std::list<string> webn;
    std::list<string> :: iterator n;
    std::list<string> :: iterator next;
    std::list<size_t> webs;
    std::list<size_t> :: iterator s;
  // TO BE COMPLETED
};

BrowserHistory::BrowserHistory(){
webn.push_back("");
webs.push_back(0);
n = webn.begin();
s = webs.begin();
}

void BrowserHistory::visitSite(string url, size_t filesize){
    size_t counter = 1;
    size_t holder= webn.size();
    for(std::list<string> :: iterator i = webn.begin(); *i!=*n;++i){
      counter++;
    }
    if(counter < holder){
    for(size_t i = counter; i < holder;i++){
    webn.pop_back();
    webs.pop_back();
  }
  webn.push_back(url);
  ++n;
  webs.push_back(filesize);
  ++s;
}

  else if(*n==""){
    webn.push_back(url);
    ++n;
    webs.push_back(filesize);
    ++s;
    webn.pop_front();
    webs.pop_front();
    n = webn.begin();
    s = webs.begin();
  }
  else {
webn.push_back(url);
++n;
webs.push_back(filesize);
++s;
}
}

void BrowserHistory::backButton(){

  if(*n == webn.front()) return;
  --n;
  --s;
}

void BrowserHistory::forwardButton(){
  if(*n == webn.back()) return;
  ++n;
  ++s;
}

void BrowserHistory::readFile(string fileName){
std::ifstream myfile(fileName);
string holder1;
size_t holder2;
while(myfile >> holder1){
  myfile.ignore();
  if(holder1 =="visit"){
    myfile >> holder1;
    myfile.ignore();
    myfile >> holder2;
    myfile.ignore();
    visitSite(holder1, holder2);
  }
  else if(holder1=="back"){
    backButton();
  }
  else{
    forwardButton();
  }
}
}

string BrowserHistory::currentUrl(){
if(webn.empty()) return "";
  return *n;
}

size_t BrowserHistory::currentPageSize(){
  if(webs.empty()) return 0;
  return *s;
}

  size_t BrowserHistory::getHistoryLength(){
    size_t i = webn.size();
    return i;
  }
