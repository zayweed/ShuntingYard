//blueprint for binary tree node
#include <bits/stdc++.h>

using namespace std;

class BNode {
    //private variables
    char c;
    BNode* right;
    BNode* left;
    BNode* next;

 public:
    BNode(char newC); //constructer
    //getters
    BNode* getLeft();
    BNode* getRight();
    BNode* getNext();
    //setters
    void setLeft(BNode* newLeft);
    void setRight(BNode* newRight);
    void setNext(BNode* newNext);
    ~BNode(); //destructer
  
};
