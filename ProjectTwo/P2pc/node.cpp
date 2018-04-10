#include "node.h"

template<typename Type>
Node<Type>::Node(Type contents, Node* node){
    contents_ = contents;
    next_ = node;
}

template<typename Type>
void Node<Type>::set_Next_Node(Node* node){
    next_ = node;
}

template<typename Type>
void Node<Type>::set_Contents(Type contents){
    contents_ = contents;
}

template<typename Type>
Node<Type> *Node<Type>::next_Node(){
    return next_;
}

template<typename Type>
Type Node<Type>::contents(){
    return contents_;
}