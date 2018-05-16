/*
Robert prouty
5/15/18
Programming project #3
bs_node.h
*/
#include <string>
#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H

class BSTNode {
    private:
        string word_;           
        int weight_;            
        BSTNode* leftChild_;   
        BSTNode* rightChild_;  
        
    public:
        /* Default constructor.*/
        BSTNode();

        BSTNode(int weight, string word);
        
        /*will return the wieght of the word*/
        int weight();
        /*returns the contents of the node*/
        string contents();
        
        /*returns left child*/
        BSTNode* leftChild();

        /*returns right child*/
        BSTNode* rightChild();        
        
        const int weight() const;

        const string contents() const;

        const BSTNode* leftChild() const;

        const BSTNode* rightChild() const;       
        
        void setWord(string word);

        void setWeight(int weight);       
        
        /*sets the left child to an adress
        @param adress - the adress that is passed in
        */
        void setLeftChild(BSTNode* address);
       
        /*sets the right child to an adress
        @param adress - the adress that is passed in
        */
        void setRightChild(BSTNode* address);
};




#endif