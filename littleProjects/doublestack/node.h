#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
class Node {
    private:
        string contents_;
        Node* next_;
        Node* prev_;
    public:
        Node(string contents = "", Node* node = NULL);
        void set_contents(string string);
        void set_next_node(Node* node);
        Node* next_node();
        Node* previous_node();
        string contents();
};
#endif