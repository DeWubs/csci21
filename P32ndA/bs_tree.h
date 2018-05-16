/*
Robert prouty
5/15/18
Programming project #3
bs_tree.h
*/
#ifndef TREE_H
#define TREE_H

// Includes
#include "bst_node.h"
#include <string>
#include <vector>
#include <sstream>
using std::stringstream;
using std::string;
using std::vector;



class BSTree {
     private:
        string inOrder(BSTNode* node, string output);
        bool insert(BSTNode* node, string word, int weight);
        void clear(BSTNode* node);
        bool removeNode(string word, BSTNode* node, BSTNode* parent);
        string findMin(BSTNode* node);
        int findWeight(BSTNode* node, string word);
        string samePrefix(BSTNode* node, string prefix, string output);
        int size_;       
        BSTNode* root_;  
        
    public:
        /* Default constructor.*/
        BSTree();
        
        /* Returns the size of the tree*/
        int size();
        
        /* Print out the contents of the tree in order*/
        string inOrder();
        
        /* inserts a node into the tree*/
        bool insert(string word, int weight);
        
        void clear();
        
        /* removes a node from the tree*/
        bool removeNode(string word);

        string findMin();
        
        int findWeight(string word);

        string samePrefix(string prefix);
        
   
};

#endif