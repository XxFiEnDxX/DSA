

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

// reverse print RECURSIVE
node* recReverse(node*head){
    if (head->next==NULL or head==NULL)
    {
        return head;
    }
    node* shead = recReverse(head->next);

    // node* temp = shead;
    // while (temp->next!=NULL)
    // {
    //     temp = temp->next;
    // }

    head->next->next = head;
    head->next = NULL;
    return shead;    
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
//Midpoint of a Linkerd List;
//Runner Technique

node* midpoint(node*head){
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    
    node*slow = head;
    node*fast  = head->next;

    while (fast!= NULL && fast->next !=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    node *head;
    node *head2;

    cin >> head;
    // cout << head;

    // head2 = recReverse(head2);

    node* mid = midpoint(head);

    cout<<mid->data;

    // print(head2);
    return 0;
}