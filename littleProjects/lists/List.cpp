#include <iostream>
#include <cstdlib>
#include "List.h"
using namespace std;

List::List(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::addNode(int addData){
    node Ptr n = new node;
    n ->next = NULL;
    n->data = addData;
    
    if(head != NULL){
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
    else{
        head = n;
    }
}

void List::deleteNode(int delData){
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while(curr != NULL && curr->data != delData){
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        cout << delData << " was not in the list\n";
        delete delPtr
    }
    else{
        delPtr = curr;
        curr = curr->next;
        tem->next = curr;
        delete delPtr;
        cout << "the value " << delData << " was deleted\n"; 
    }
}

void List::printList(){
    curr = head;
    while(curr != NULL){
        cout << curr->data << endl;
        curr = curr->next;
    }
}
