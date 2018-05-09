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
        Node <Type>* head_;
        
    public:
        /*constructors and destructors*/
        Stack(){
            head_ = NULL;
        }
        ~Stack(){
            if (head_ != NULL){
                clear();
            }
        }
        /*will push a value ontop of the stack
        @param value
        */
        void push(Type data){
            Node<Type>* temp_ptr = new Node<Type>;
            if (head_ == NULL){
                temp_ptr->set_contents(data);
                head_ = temp_ptr;
            }
            // Sets the head to the new node
            else{
                temp_ptr->set_contents(data);
                temp_ptr->set_next_node(head_);
                head_ = temp_ptr;
            }
        }
        /*will pop a value off the top of the stack
        */
        void pop(){
            if (head_ != NULL){
                
                Node<Type>* temp_ptr = head_;
                if (head_->getNextNode() == NULL){
                    head_ = NULL;
                    delete temp_ptr;
                }
                else {
                    head_ = temp_ptr->getNextNode();
                    delete temp_ptr;
                }
            }
        }
         Type at(int index){
            Node<Type>* temp_ptr = head_;
            
            for (int i = 0; i < index; i++){
                temp_ptr = temp_ptr->getNextNode();
            }
            return temp_ptr->contents();
        }
        /*will print the constents of the stack
        */
         string print(){
            string output;
            Node<Type>* temp_ptr = head_;
            for (int i = 0; i < this->size(); i++){
                output += temp_ptr->contents();
                output += " ";
                temp_ptr = temp_ptr->getNextNode();
            }
            output = output.substr(0, output.size() - 1);
            return output;
        }
        
        void clear(){
            Node<Type>* temp_ptr = head_;
            while (temp_ptr->getNextNode() != NULL){
                Node<Type>* suc_node = temp_ptr->getNextNode();
                delete temp_ptr;
                temp_ptr = suc_node;
            }
            delete temp_ptr;
            head_ = NULL;
        }
        
        int size(){
            int temp_size = 1;
            Node<Type>* temp_ptr = head_;
            if (head_ == NULL){
                temp_size = 0;
            }
            else if (head_->getNextNode() != NULL){
                while(temp_ptr->getNextNode() != NULL){
                    temp_size++;
                    temp_ptr = temp_ptr->getNextNode();
                }
            }
            return temp_size;
        }
        
};

#endif


