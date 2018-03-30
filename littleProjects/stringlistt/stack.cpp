#include "stack.h"

Stack::Stack(string contents, Stack *next){
    contents_ = contents;
    next_ = next;
}

Stack::~Stack(){
    
}


bool Stack::empty(){

}

void Stack::push(string value){
    
    Node *newNode = new Node(value);
    next_ = newNode;
}

void Stack::pop(string value){
    
}

void Stack::print(){
    
}