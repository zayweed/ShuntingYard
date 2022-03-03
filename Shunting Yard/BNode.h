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
    char getChar();
    BNode* getRight();
    BNode* getLeft();
    BNode* getNext();
    //setters
    void setRight(BNode* newRight);
    void setLeft(BNode* newLeft);
    void setNext(BNode* newNext);
    ~BNode(); //destructer
  
};
