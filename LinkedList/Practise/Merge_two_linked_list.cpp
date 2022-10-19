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
        cout << head->data << "> ";
        head = head->next;
    }
    cout << endl;
}

// Taking Input In Linked List----------->

// void input(node*&head){}

node *take_input_2()
{
    int d;
    cin >> d;

    node *head = NULL;

    while (d != -1)
    {
        insertAtTail(head, d);
        cin >> d;
    }
    return head;
}

// Without cascading
//  void operator<<(ostream &os, node*head){
//      print(head);
//      return;}

// With cascading
ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os; // cout
}

istream &operator>>(istream &is, node *&head)
{
    head = take_input_2();
    return is;
}

node *midPoint(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node* mergeShot(node*head){
    if (head== NULL || head->next == NULL)
    {
        return head;
    }
    
    node* mid = midPoint(head);
    node* a = head;
    node* b = mid->next;
    mid->next = NULL;

    a = mergeShot(a);
    b = mergeShot(b);

    node *c = merge(a,b);

    return c;
}

int main()
{

    node *head;
    node *head2;

    cin >> head;

    // cout<<"Mid point is "<<midPoint(head)->data;

    node* mergeLL = mergeShot(head);
    cout << mergeLL;

    return 0;
}