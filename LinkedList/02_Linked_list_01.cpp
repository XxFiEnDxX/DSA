#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

// LinkedList Class (Object Oriented)
// class LinkedList
// {
//     node *head;
//     node *tail;

// public:
//     LinkedList()
//     {
//     }

//     void insert(int d)
//     {
//     }
// };

// Linked-List Function (Procedural Programming)
void build(){

}
void insertAtHead(node*&head,int d){ //passing a pointer by reference
    if(head==NULL){
        head = new node(d);
        return ;
    }
    node *n = new node(d);
    // (*n).next = head;
    n->next = head;
    head = n;
}

void print(node*head){
    while (head!=NULL)
    {
        cout<<head->data<<" ->";
        head = head->next;
    }
        cout<<endl;
    
}

int main()
{
    node*head = NULL;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);

    print(head);
    print(head);
    return 0;
}