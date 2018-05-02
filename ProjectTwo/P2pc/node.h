/*
node.h
Robert Prouty
april 10th 2018
header for a node that makes a linked list
*/
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef NODE_H
#define NODE_H

template <typename Type>
class Node{
    private:
        Type contents_;
        Node* next_;
        
    public:
        /*constuctor sets the values
        @param string is the value of the element
        @param Node* is the pointer to the node
        */
        Node(Type contents = "", Node* node = NULL);
        /*
        setters for the nodes
        */
        void set_Contents(Type value);
        void set_Next_Node(Node* node);
        Node* next_Node();
        Type contents();
};
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
#endif