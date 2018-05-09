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
class Queue{
    private:
        Node <Type>* head_;
        Node <Type>* tail_;
       
    public:
        /*
        constructor and destructors for queue
        */
       Queue(){
            head_ = NULL;
            tail_ = NULL;
        }
        
        ~Queue(){
            if (head_ != NULL) {
                clear();
            }
        }
        /*pushes a value onto the back of the queue
        @param value
        */
        void push(Type data){
            Node<Type>* temp_ptr = new Node<Type>;
            if (head_ == NULL){
                temp_ptr->set_contents(data);
                head_ = temp_ptr;
                tail_ = temp_ptr;
            }
            else{
                temp_ptr->set_contents(data);
                tail_->set_next_node(temp_ptr);
                tail_ = temp_ptr;
            }
        }
        /*pops a value off the front queue*/
        void pop(){
            if (head_ != NULL){
                
                Node<Type>* temp_ptr = head_;

                if (head_ == tail_){
                    head_ = NULL;
                    tail_ = NULL;
                    delete temp_ptr;
                }
                else{
                    head_ = temp_ptr->getNextNode();
                    delete temp_ptr;
                }
            }
        }
        /*will return a value at a location in the queue
        @param int index
        @param return Type*/
        Type at(int index){
            Node<Type>* temp_ptr = head_;
                
                for (int i = 0; i < index; i++){
                    temp_ptr = temp_ptr->getNextNode();
                }
            return temp_ptr->contents();
        }
        /*will clear the whole queue and reset the head and tail
        */
        void clear(){
            Node<Type>* temp_ptr = head_;
            while (temp_ptr != tail_){
                Node<Type>* suc_node = temp_ptr->getNextNode();
                delete temp_ptr;
                temp_ptr = suc_node;
            }
            delete temp_ptr;
            tail_ = NULL;
            head_ = NULL;
        }
        
         /*
         * Returns number of items in queue
         * @return int
         */
        int size(){
            int temp_size = 1;
            Node<Type>* temp_ptr = head_;
            if (head_ != tail_){
                while(temp_ptr != tail_){
                    temp_size++;
                    temp_ptr = temp_ptr->getNextNode();
                }
            }
            
            if (head_ == NULL){
                temp_size = 0;
            }
            
            return temp_size;
        }
        
        /*
         * will return all of the values int he queue front to back
         * @return string 
         */
        string print(){
            string output;
            Node<Type>* temp_ptr = head_;
            
            for (int i = 0; i < this->size(); i++) {
                output += temp_ptr->contents();
                output += " ";
                temp_ptr = temp_ptr->getNextNode();
            }
            output = output.substr(0, output.size() - 1);
            
            return output;
        }
        
};

#endif

