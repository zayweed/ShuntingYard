#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>

using namespace std;

struct Stack {

  Stack* prev;
  Stack* next;
  char value;

};

#endif