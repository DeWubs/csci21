#include "stack.h"
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
