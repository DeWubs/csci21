/*
Robert prouty
5/15/18
Programming project #3
bs_tree.cpp
*/
#include "bs_tree.h"
 /* Default constructor.*/
BSTree::BSTree(){
    size_ = 0;
    root_ = NULL;
}

/* Returns the size of the tree*/
int BSTree::size(){
    return size_;
}


string BSTree::inOrder(BSTNode* node, string output){
    //if there is nothing, it will return nothing
    if (size_ == 0){
        return "";
    }
    //If there is a left child, it will call it again on the left child
    //It will go Until there are no more left children
    if (node->leftChild() != NULL){
        output = inOrder(node->leftChild(), output);
    }
    
    stringstream ss;
    ss << node->contents() << " ";
    output += ss.str();

    if (node->rightChild() != NULL){
        output = inOrder(node->rightChild(), output);
    }
    //Return the string of words
    return output;
}

void BSTree::clear(BSTNode* node){

    if (node->leftChild() != NULL){
        clear(node->leftChild());
    }
 
    if (node->rightChild() != NULL){
        clear(node->rightChild());
    }

    delete node;
    size_--;
}

//inserts a node into the tree
//@param BSTNode
//@param string word
//@param int weight
bool BSTree::insert(BSTNode* node, string word, int weight){
    //If the weight of the node to be inserted is less than the current node, go left
    if (weight <= node->weight()) {
        //if there is a left child, go left
        if (node->leftChild() != NULL){
            return insert(node->leftChild(), word, weight);
        }
        //make it as the new node
        else{
            BSTNode* newNode = new BSTNode;
            newNode->setWeight(weight);
            newNode->setWord(word);
            node->setLeftChild(newNode);
            size_++;
            return true;
        }
    }
    //If the weight of the inserted node is larger it goes to the right
    else if (weight > node->weight()){
        //If there is a right child, go right
        if (node->rightChild() != NULL){
            return insert(node->rightChild(), word, weight);
        }
        //make it as the new node
        else{
            BSTNode* newNode = new BSTNode;
            newNode->setWeight(weight);
            newNode->setWord(word);
            //Set the current node's right child to the new node
            node->setRightChild(newNode);
            size_++;
            return true;
        }
    }

    else{
        return false;
    }
}

int BSTree::findWeight(BSTNode* node, string word){
    //if there is nothing, return nothing
    if (size_ == 0){
        return 0;
    }
    //Start looking for it and return its weight if found
    if(node->contents() == word){
        return node->weight();   
    }
    
    //If there is a left child, call the function again on the left child
    if (node->leftChild() != NULL){
        return findWeight(node->leftChild(), word);
    }
    

    //If thre is a right child, call the function again on the right child, after
    if (node->rightChild() != NULL){
        return findWeight(node->rightChild(), word);
    }
    
        return 0;   
    
}

string BSTree::findMin(BSTNode* node){
    //if there is still a left child, keep going left
    if (node->leftChild() != NULL){
        return findMin(node->leftChild());
    }
    else{
        //return the leftmost child
        return node->contents();
    }
}

string BSTree::samePrefix(BSTNode* node, string prefix, string output){
    //if there is nothing, return nothing
    if (size_ == 0){
        return "";
    }

    if (node->rightChild() != NULL){
        output = samePrefix(node->rightChild(), prefix, output);
    }
    stringstream ss;
    //At rightmost node, start comparing the word and prefix
    if(node->contents().size() >= prefix.size()){
        if(prefix == node->contents().substr(0, prefix.size())) {
            ss << node->contents() << "\n";
        }
    } 
    else{
        if(node->contents() == prefix.substr(0, node->contents().size())) {
            ss << node->contents() << "\n";
        }
    }
    output += ss.str();

    if (node->leftChild() != NULL){
        output = samePrefix(node->leftChild(), prefix, output);
    }
    //Return the string of words
    return output;
}

string BSTree::inOrder(){                        
    //call the inorder(root, "") function in class to gain access to the root
    return inOrder(root_, "");
}

bool BSTree::insert(string word, int weight){

    //If there is nothing there, make this new node the root
    if (root_ == NULL){
        root_ = new BSTNode;
        root_->setWeight(weight);
        root_->setWord(word);
        
        size_++;
        return true;
    }
    //If there is at least one node, call insert(root, val) to handle it
    else{
        return insert(root_, word, weight);
    }
}

/*Clear the binary search tree. This gets rid of all the current nodes*/
void BSTree::clear(){
    //If there is nothing in the tree, do nothing
    if (root_ == NULL){
        return;
    }
    //Otherwise call clear(node) starting at the root and finally set the root to null
    else{
        clear(root_);
        root_ = NULL;
    }
}

string BSTree::findMin(){
    //if there is no node, return 0
    if (root_ == NULL) {
        return "";
    }
    //otherwise call findMin(node) with the root
    else{
        return findMin(root_);
    }
}
int BSTree::findWeight(string word){
    return findWeight(root_, word);   
}


string BSTree::samePrefix(string prefix){
    string temp;
    return samePrefix(root_, prefix, temp);
}