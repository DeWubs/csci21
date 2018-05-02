#include "bst_node.h"
BSTNode::BSTNode(){
    contents_ = 0;
    left_child_ = NULL;
    right_child_ = NULL;
}

BSTNode::BSTNode(int contents){
    contents_ = contents;
    left_child_ = NULL;
    right_child_ = NULL;
}

int BSTNode::contents() const{
    return contents_;
}

int BSTNode::contents(){
    return contents_;
}

void BSTNode::set_contents(int val){
    contents_ = val;
}

BSTNode* BSTNode::left_child(){
    return left_child_;
}

BSTNode* BSTNode::left_child() const{
    return left_child_;
}

void BSTNode::set_left_child(BSTNode* location){
    left_child_ = location;
}

BSTNode* BSTNode::right_child(){
    return right_child_;
}

BSTNode* BSTNode::right_child() const{
    return right_child_;
}

void BSTNode::set_right_child(BSTNode* location){
    right_child_ = location;
}