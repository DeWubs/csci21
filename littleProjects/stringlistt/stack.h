#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "node.h"
#ifndef STACK_H
#define STACK_H
class Stack{
    private:
       Node *top_;
       int size_;
        
    
    public:
       Stack();
       ~Stack();
       void push(string value);
       string pop();
       string print();
       bool empty();
       int size();
};

#endif
// c++ is being weird justin and i are having the same issuue