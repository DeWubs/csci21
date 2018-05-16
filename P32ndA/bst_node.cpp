/*
Robert prouty
5/15/18
Programming project #3
bs_node.cpp
*/
#include "bst_node.h"

/* Default constructor.
sets weight to 0
sets word to nothing ""
left child to null
and right child to null
*/
BSTNode::BSTNode(){
    weight_ = 0;
    word_ = "";
    leftChild_ = NULL;
    rightChild_ = NULL;
}
/* Default constructor.
sets weight to weight
sets word to a word that is passed in 
left child to null
and right child to null
*/
BSTNode::BSTNode(int weight, string word){
    weight_ = weight;
    word_ = word;
    leftChild_ = NULL;
    rightChild_ = NULL;
}

int BSTNode::weight(){
    return weight_;
}

string BSTNode::contents(){
    return word_;
}

BSTNode* BSTNode::leftChild(){
    return leftChild_;
}

BSTNode* BSTNode::rightChild(){
    return rightChild_;
}

const int BSTNode::weight() const{
    return weight_;
}

const string BSTNode::contents() const{
    return word_;
}

const BSTNode* BSTNode::leftChild() const{
    return leftChild_;
}

const BSTNode* BSTNode::rightChild() const{
    return rightChild_;
}

void BSTNode::setWord(string word){
    word_ = word;
}

void BSTNode::setWeight(int weight){
    weight_ = weight;
}

void BSTNode::setLeftChild(BSTNode* address){
    leftChild_ = address;
}

void BSTNode::setRightChild(BSTNode* address){
    rightChild_ = address;
}