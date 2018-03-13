#ifndef LIST_H
#define LIST_H
class list{
    private:
       struct node{
            int data;
            node* next;
        };
        node* head;
        node* curr;
        node* temp;
    public:
        List();
        void addNode(int addData);
        void deleteNode(int delData);
        void printList();
        
};

#endif 