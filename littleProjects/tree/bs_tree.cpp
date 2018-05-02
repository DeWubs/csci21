#include "bs_tree.h"
#include <iostream>
using namespace std;

BSTree::BSTree(){
    size_ = 0;
    root_ = NULL;
}

int BSTree::size(){
    return size_;
}

string BSTree::InOrder(BSTNode* node, string op){
    if(size_ == 0){
        return "";
    }
    
    if(node->left_child() != NULL){
        op = InOrder(node->left_child(), op);
    }
    
    stringstream ss;
    ss << node->contents() << " ";
    op += ss.str();
    
    if(node->right_child() != NULL){
        op = InOrder(node->right_child(), op);
    }
    
    return op;
}

string BSTree::InOrder(){
    return InOrder(root_, "");
}

bool BSTree::Insert(BSTNode* node, int val){
    if(node == NULL){
        node = new BSTNode;
        node->set_contents(val);
        size_++;
        return true;
    }
    else if (val < node->contents()){
        if(node->left_child() != NULL){
            return Insert(node->left_child(), val);
        }
        else{
            BSTNode* tempptr = new BSTNode;
            tempptr->set_contents(val);
            node->set_left_child(tempptr);
            size_++;
            return true;
        }
    }
    else if(val > node->contents()){
        if(node->right_child() != NULL){
            return Insert(node->right_child(), val);
        }
        else{
            BSTNode* tempptr = new BSTNode;
            tempptr->set_contents(val);
            node->set_right_child(tempptr);
            size_++;
            return true;
        }
    }
    else{
        return false;
    }
}

bool BSTree::Insert(int val){
    if(root_ == NULL){
        root_ = new BSTNode;
        root_->set_contents(val);
        size_++;
        return true;
    }
    else{
        return Insert(root_, val);
    }
}

void BSTree::Clear(){
    if(root_ == NULL){
        return;
    }
    else{
        Clear(root_);
    }
}

void BSTree::Clear(BSTNode* node){
    if(node->left_child() != NULL){
        Clear(node->left_child());
    }
    
    if(node->right_child() != NULL){
        Clear(node->right_child());
    }
    
    delete node;
    size_--;
}