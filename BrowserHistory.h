#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>     // std::next, std::prev

using std::string;

struct Node{
    Node *next; 
    string data; 
};

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
    Node *head; 
    Node *tail; 
  // TO BE COMPLETED
};
