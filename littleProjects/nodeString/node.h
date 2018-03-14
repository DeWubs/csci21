#include <cstdlib>
#include <iostream>
#include <string>
#include "catch.hpp"
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node{
    private:
        string data;
        Node* next;
    public:
        void setData(string newString);
        void setNext(Node* newNext);
        
        string getData();
        string contents();
};

#endif