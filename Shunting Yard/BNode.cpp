//binary tree node functions
#include <bits/stdc++.h>

#include "BNode.h"

using namespace std;

BNode::BNode(char newC) { //constructer
    c = newC;
    right = NULL;
    left = NULL;
    next = NULL;
}

BNode* BNode::getLeft() { //getter for left node
    return left;
}
BNode* BNode::getRight() { //getter for right node
    return right;
}

BNode* BNode::getNext() { //getter for next node 
    return next;
}

void BNode::setLeft(BNode* newLeft) { //setter for left node
    left = newLeft;
}

void BNode::setRight(BNode* newLight) { //setter for right node
    right = newLight;
}

void BNode::setNext(BNode* newLext) { //setter for next node
    next = newLext;
}

BNode::~BNode() { //destructer
  
}