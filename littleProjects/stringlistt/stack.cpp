#include "stack.h"

Stack::Stack(){
    top_ = NULL;
    size_ = 0;
}

Stack::~Stack(){
    while(!empty()){
        pop();
    }
}

void Stack::push(string value){
    Node *newNode = new Node;
    
    newNode->set_contents(value);
    
    newNode->set_next_node(top_);
    
    top_ = newNode;
    
    size_++;
}

string Stack::pop(){
    if(!empty()){
        
        
        string data = top_->contents();
    
        Node *prevtop_ = top_;
        top_ = top_->next_node();
        delete prevtop_;
        size_--;
        return data;
    }
    else{
            return "!@*$#%";
        }
    }


string Stack::print(){
    string value;
    Node *iterator = top_;
    while(iterator != NULL) {
        value += iterator->contents() + " ";
        iterator = iterator->next_node();
    }
    
    return value;
}
    

bool Stack::empty(){
    if(top_ == NULL) {
        return true;
    }
    else {
        return false;
    }
}


int Stack::size(){
    return size_;
}