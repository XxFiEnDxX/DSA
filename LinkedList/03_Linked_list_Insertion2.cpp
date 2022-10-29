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
void build()
{
}
void insertAtHead(node *&head, int d)
{ // passing a pointer by reference
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    // (*n).next = head;
    n->next = head;
    head = n;
}

int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertAtTail(node*&head,int d){
    if (head==NULL)
    {
        head = new node(d);
        return;
    }
    node*tail = head;
    while (tail->next!=NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void insertInMiddle(node *&head, int d, int p)
{
    if (head == NULL or p == 0)
    {
        insertAtHead(head, d);
        return;
    }
    else if (p > length(head))
    {
        insertAtTail(head, d);
    }
    else
    {
        node*temp = head;
        for (int i = 1; i <p; i++)
        {
            temp = temp->next;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}



void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    print(head);

    insertInMiddle(head, 4, 4);
    insertInMiddle(head, 5, 5);
    insertInMiddle(head, 6, 1);
    insertInMiddle(head, 99, 10);
    insertInMiddle(head, 99, 0);
    // insertAtTail(head, 7);
    // insertAtTail(head, 8);
    // insertAtTail(head, 9);
    // insertAtTail(head, 10);

    print(head);
    return 0;
}