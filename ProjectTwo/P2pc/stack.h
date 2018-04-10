/*
queue.h
Robert Prouty
april 10th 2018
header for a stack 
*/
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "node.h"
using namespace std;

#ifndef STACK_H
#define STACK_H

template<typename Type>
class Stack {
    private:
        Node <Type> *top_;
        int size_;
    public:
        Stack();
        ~Stack();
        void push(Type value);
        Type pop();
        string print();
        bool empty();
        int size();
};
#endif


