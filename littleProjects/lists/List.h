#ifndef LIST_H
#define LIST_H
 struct node{
        int data;
        node* next;
    };
class List{
    private:
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