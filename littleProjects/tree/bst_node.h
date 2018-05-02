#ifndef BST_NODE_H
#define BST_NODE_H
#include <cstddef>

class BSTNode{
    private:
        int contents_;
        BSTNode* left_child_;
        BSTNode* right_child_;
    
    public:
        BSTNode();
        BSTNode(int contents);
        int contents() const;
        int contents();
        void set_contents(int val);
        BSTNode* left_child();
        BSTNode* left_child() const;
        void set_left_child(BSTNode* location);
        BSTNode* right_child();
        BSTNode* right_child() const;
        void set_right_child() const;
        void set_right_child(BSTNode* location);
};

#endif