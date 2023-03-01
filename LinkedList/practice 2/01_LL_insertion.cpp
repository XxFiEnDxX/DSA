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
}


int main()
{
    node *head = build();
    printLL(head);
    return 0;
}