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

node *insertAtHead(node *head, int d)
{
    if (head == NULL)
    {
        return new node(d);
    }
    node *temp = new node(d);
    temp->next = head;
    head = temp;
    return head;
}

node *build()
{
    int d;
    cin >> d;

    node *head = NULL;

    while (d != -1)
    {
        head = insertAtHead(head, d);
        cin >> d;
    }
    return head;
}

void print(node* head){
    while (head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    
}

int main()
{
    node *head = build();
    print(head);
    return 0;
}