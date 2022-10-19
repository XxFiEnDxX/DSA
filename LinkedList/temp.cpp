#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

// INSERTING NODES =>
void insertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
    return;
}

// TAKING INPUTS =>
node *take_Input()
{
    node *head = NULL;
    int d = 0;
    cin >> d;
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    return head;
}

////// PRINTING NODES =>
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
    return;
}

//reverse print
void reverse(node*&head){
    node*P = NULL;
    node*C = head;
    node*N = NULL;
    while (C != NULL)
    {
        N = C->next;
        C->next = P;
        P=C;
        C=N;
    }
    head = P;
}

////// O/I OPERATOR OVERLOADING =>

istream &operator>>(istream &is, node *&head)
{
    head = take_Input();
    return is;
}

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}

int main()
{
    node *head;
    node *head2;

    cin >> head >> head2;
    cout << head << head2;

    reverse(head2);

    print(head2);
    return 0;
}