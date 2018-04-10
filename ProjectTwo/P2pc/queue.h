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
        Queue();
        ~Queue();
        void push(Type value);
        Type pop();
        string print();
        bool empty();
        int size();
};

#endif

