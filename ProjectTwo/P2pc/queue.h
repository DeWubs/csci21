/*
queue.h
Robert Prouty
april 10th 2018
header for a queue 
*/
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "node.h"
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H
template<typename Type>
class Queue {
    private:
        Node <Type> *front_;
        Node <Type> *back_;
        int size_;
    public:
        /*
        constructor and destructors for queue
        */
        Queue();
        ~Queue();
        /*pushes a value onto the back of the queue
        @param value
        */
        void push(Type value);
        /*pops a value off the front queue*/
        Type pop();
        /*prints the contents of the queue*/
        string print();
        bool empty();
        int size();
};

Queue<Type>::Queue(){
    front_ = NULL;
    back_ = NULL;
    size_ = 0;
}




Queue<Type>::~Queue(){
    Node<Type>* temp;
    while(!empty()) {
        temp = front_;
        front_ = front_->next_node();
        delete temp;
    }
}



void Queue<Type>::push(Type value){
   
    Node<Type> *newNode = new Node<Type>;
    
 
    newNode->set_contents(value);
    
   
    newNode->set_next_node(NULL);
    
    if(front_ == NULL) {
        front_ = newNode;
    }
 
    else {
        back_->set_next_node(newNode);
    }
    
    back_ = newNode;
    
    size_++;
}


Type Queue<Type>::pop(){
   
    if(!empty()) {
    
        Type data = front_->contents();
        
        Node<Type> *prevfront_ = front_;
        front_ = front_->next_node();
        
        delete prevfront_;
        
        size_--;

        return data;
    }
    else {
        return "*@!?";
    }
}


string Queue<Type>::print(){
    stringstream ss;
    
    Node<Type> *iterator = front_;
    while(iterator != NULL) {
        ss << iterator->contents() << " ";
        iterator = iterator->next_node();
    }
    return ss.str();
}


bool Queue<Type>::empty(){
    if(front_ == NULL) {
        return true;
    }
    else {
        return false;
    }
}



int Queue<Type>::size(){
    return size_;
}

#endif

