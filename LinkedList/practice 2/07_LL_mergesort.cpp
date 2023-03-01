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
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
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
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *mid = midPoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    node *c = merge(a, b);
    return c;
}

int main()
{
    node *head;

    cin >> head;
    cout << head;

    head = mergeSort(head);

    cout << head;

    return 0;
}