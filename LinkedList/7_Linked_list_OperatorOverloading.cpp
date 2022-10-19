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

void insertInMiddle(node *&head, int d, int p)
{
    if (head == NULL or p == 0)
    {
        insertAtHead(head, d);
        return;
    }
    else if (p > length(head))
    {
        // insertAtTail(head, data);
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < p; i++)
        {
            temp = temp->next;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void deletionHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}

void deletionTail(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    delete tail;
    return;
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

// Taking Input In Linked List----------->

// void input(node*&head){}

node* take_input_2(){
    int d;
    cin>>d;

    node*head=NULL;
    
    while (d!=-1)
    {
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

//Without cascading
// void operator<<(ostream &os, node*head){
//     print(head);
//     return;}

//With cascading
ostream& operator<<(ostream &os, node*head){
    print(head);
    return os;  //cout
}

istream& operator>>(istream &is,node*&head){
    head = take_input_2();
    return is;
}



int main()
{
    // <====OverLoading 'COUT<<' =====>
    // node *head = take_input_2();
    // node *head2 = take_input_2();
    // cout<<head;
    // cout<<head2;

    // cout<<head<<head2; //Cascading of operators

    // <====OverLoading 'CIN>>' =====>

    node*head;
    node*head2;
    cin>>head>>head2;
    cout<<head<<head2;

    // insertAtHead(head, 3);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 0);

    // print(head);

    // insertInMiddle(head, 4, 4);
    // insertInMiddle(head, 5, 5);
    // insertInMiddle(head, 6, 6);
    // insertAtTail(head, 7);
    // insertAtTail(head, 8);
    // insertAtTail(head, 9);
    // insertAtTail(head, 10);

    // print(head);

    // deletionHead(head);
    // deletionHead(head);
    // deletionTail(head);

    // print(head);

    return 0;
}