#ifndef BS_TREE_H
#define BS_TREE_H

#include "bst_node.h"
#include <sstream>
#include <string>
using namespace std;

class BSTree{
    private:
        int size_;
        BSTNode* root_;
    public:
        BSTree();
        int size();
        string InOrder(BSTNode* node, string op);
        string InOrder();
        bool Insert(BSTNode* node, int val);
        bool Insert(int val);
        void Clear();
        void Clear(BSTNode* node);
};

#endif