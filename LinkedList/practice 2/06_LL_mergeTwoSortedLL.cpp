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

void insertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

node *build()
{
    int ele;
    cin >> ele;

    node *head = NULL;

    while (ele != -1)
    {
        insertAtHead(head, ele);
        cin >> ele;
    }
    return head;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

istream &operator>>(istream &ip, node *&head)
{
    head = build();
    return ip;
}

ostream &operator<<(ostream &op, node *head)
{
    printLL(head);
    return op;
}

node *midPoint(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    node *c;

    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else if (a->data > b->data)
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main()
{
    node *head;
    node *head2;

    cin >> head >> head2;
    cout << head << head2;

    cout<<merge(head,head2);

    return 0;
}