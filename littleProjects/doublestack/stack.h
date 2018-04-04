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
       Node *iterator_;
       Node * prev_;
       int size_;
        
    
    public:
       Stack();
       ~Stack();
       void push(string value);
       string pop();
       string print();
       bool empty();
       int size();
       string at(int index);
};

#endif
// c++ is being weird justin and i are having the same issuue