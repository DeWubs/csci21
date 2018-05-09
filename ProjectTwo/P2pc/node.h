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
        Node<Type>* next_node_;
        
    public:
        /*constuctor sets the values
        */
        Node(){
            next_node_ = NULL;
        }
        Node(Type dataInit, Node<Type>* next){
            contents_ = dataInit;
            next_node_ = next;
        }
        /*
        accessors and mutators for the nodes
        */
        Node<Type>* getNextNode(){
            return next_node_;
        }
        
        Type contents(){
            return contents_;
        }
        
        void set_contents(Type data){
            contents_ = data;
        }
        
        void set_next_node(Node<Type>* next_node){
            next_node_ = next_node;
        }
        
};

#endif