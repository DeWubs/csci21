#include "node.h"
Node::Node(string contents, Node* node){
    contents_ = contents;
    next_ = node;
}
void Node::set_contents(string contents){
    contents_ = contents;
}
void Node::set_next_node(Node* node){
    next_ = node;
}
Node* Node::next_node(){
    return next_;
}
Node* Node::previous_node(){
    return prev_;
}
string Node::contents(){
    return contents_; 
}
