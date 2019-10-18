#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>     // std::next, std::prev

using std::string;

struct Node{
    Node *next;
    Node *prev;
    string data;
    size_t data1;
    Node(): data(""), data1(0), next(nullptr), prev(nullptr) {}
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
    Node *curr;
    Node *head;
    Node *tail;
    size_t size;
  // TO BE COMPLETED
};

BrowserHistory::BrowserHistory(){
  head = new node;
  tail = new node;
  Curr = nullptr;
  head->next = tail;
  tail->prev = head;
}

void BrowserHistory::visitSite(string url, size_t filesize){
    Node *ptr = new Node;
    ptr->data = url;
    ptr->data1 = filesize;
    ptr->next = tail;
    ptr->prev =tail->prev;
    ptr->prev->next = ptr;
    tail->prev = ptr;
    Curr = ptr;
}

void BrowserHistory::backButton(){
  if(Curr->prev->data1 == 0) return;
  Curr = Curr->prev;
}

void BrowserHistory::forwardButton(){
  if(Curr->next->data1 == 0) return;
  Curr = Curr->next;
}
