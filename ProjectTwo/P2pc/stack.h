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
        /*constructors and destructors*/
        Stack();
        ~Stack();
        /*will push a value ontop of the stack
        @param value
        */
        void push(Type value);
        /*will pop a value off the top of the stack
        */
        Type pop();
        /*will print the constents of the stack
        */
        string print();
        bool empty();
        int size();
};
template<typename Type>
Stack<Type>::Stack(){
    top_ = NULL;
    size_ = 0;
}

template<typename Type>
Stack<Type>::~Stack(){
    while(!empty()) {
        pop();
    }
}


template<typename Type>
void Stack<Type>::push(Type value){

    Node<Type> *newNode = new Node<Type>;
    
    newNode->set_contents(value);
    
    newNode->set_next_node(top_);
    
   
    top_ = newNode;
    
    size_++;
}

template<typename Type>
Type Stack<Type>::pop(){
  
    if(!empty()) {
        
        Type data = top_->contents();
        
        Node<Type> *prevtop_ = top_;
        top_ = top_->next_node();
        
        delete prevtop_;
    
        size_--;
        
        return data;
    }
    else {
        return "-1";
    }
}


template<typename Type>
string Stack<Type>::print(){
    //create temp stringstream to truncate values to
    stringstream ss;
    
    Node<Type> *iterator = top_;
    while(iterator != NULL) {
        ss << iterator->contents() << " ";
        iterator = iterator->next_node();
    }
    return ss.str();
}


template<typename Type>
bool Stack<Type>::empty(){
    if(top_ == NULL) {
        return true;
    }
    else {
        return false;
    }
}

template<typename Type>
int Stack<Type>::size(){
    return size_;
}
#endif


