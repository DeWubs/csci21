#include "queue.h"
template<typename Type>
Queue<Type>::Queue(){
    front_ = NULL;
    back_ = NULL;
    size_ = 0;
}



template<typename Type>
Queue<Type>::~Queue(){
    Node<Type>* temp;
    while(!empty()) {
        temp = front_;
        front_ = front_->next_node();
        delete temp;
    }
}


template<typename Type>
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



template<typename Type>
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

template<typename Type>
string Queue<Type>::print(){
    stringstream ss;
    
    Node<Type> *iterator = front_;
    while(iterator != NULL) {
        ss << iterator->contents() << " ";
        iterator = iterator->next_node();
    }
    return ss.str();
}

template<typename Type>
bool Queue<Type>::empty(){
    if(front_ == NULL) {
        return true;
    }
    else {
        return false;
    }
}


template<typename Type>
int Queue<Type>::size(){
    return size_;
}
