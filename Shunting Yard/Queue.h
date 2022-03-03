#ifndef QUEUE_H
#define QUEUE_H

#include <bits/stdc++.h>

using namespace std;

struct Queue {

  Queue* prev;
  Queue* next;
  char value;

};

#endif