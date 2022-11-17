#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int d)
    {
        data = d;
        prev = NULL;
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
    node *n = new node(d);
    n->next = head;
    head->prev = n;
    head = n;
}

void insertAtTail(node *head, int d)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    node *n = new node(d);
    head->next = n;
    n->prev = head;
}

int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void insertAtMiddle(node *&head, int d, int p)
{
    if (p == 0)
    {
        insertAtHead(head, d);
        return;
    }

    if (p > length(head))
    {
        insertAtTail(head, d);
        return ;
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < p-1; i++)
        {
            temp = temp->next;
        }
        node *n = new node(d);
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
        return;
    }
}

node *take_input()
{
    int n, d;
    cin >> n;
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        insertAtHead(head, d);
    }
    return head;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << endl;
}

istream &operator>>(istream &is, node *&head)
{
    head = take_input();
    return is;
}

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}
int main()
{
    node *head = NULL;

    cin >> head;
    cout << head;

    insertAtTail(head, 10);
    insertAtTail(head, 11);
    cout << head;

    insertAtMiddle(head, 0, 0);
    insertAtMiddle(head, 8, 3);
    insertAtMiddle(head, 100, 100);

    cout << head;
    return 0;
}