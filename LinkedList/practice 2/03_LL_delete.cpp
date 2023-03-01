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

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(node *&head)
{
    if (head == NULL)
    {

        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

int main()
{
    node *head;
    // node *head2;
    cin >> head;
    cout << head;

    // deleteAtHead(head);
    // deleteAtHead(head);
    // deleteAtHead(head);
    // deleteAtHead(head);
    // deleteAtHead(head);
    // deleteAtHead(head);

    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtTail(head);
    
    cout << head;
    return 0;
}