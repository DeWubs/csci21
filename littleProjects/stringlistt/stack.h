#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "node.h"
#ifndef STACK_H
#define STACK_H
class stack{
    private:
        string contents_;
        Node *next_;
        
    
    public:
        stack(){
            contents_ ="";
            next_ = NULL
        }
        Stack(string contents, Node* next);
        ~Stack();
        
        bool empty();
        void push(string value);
        void pop(string value);
        void print();
};

#endif
// c++ is being weird justin and i are having the same issuue