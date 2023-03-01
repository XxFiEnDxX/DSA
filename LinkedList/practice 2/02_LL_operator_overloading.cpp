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
    cout<<endl;
}

istream& operator>>(istream& ip,node*&head){
    head = build();
    return ip;
}

ostream& operator<<(ostream& op,node* head){
    printLL(head);
    return op;
}

int main()
{
    node *head;
    node *head2;
    cin>>head>>head2;
    cout<<head<<head2;
    return 0;
}