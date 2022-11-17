#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int d){
        data = d;
        next = prev = NULL;
    }
};

node* insertAtTail(node*head,int d){
        if (head == NULL)
        {
            return new node(d);
        }
        node* temp = head;
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        node* n = new node(d);
        temp->next = n;
        n->prev = temp;
        return head;  
}

node *take_input()
{
    int n, d;
    cin >> n;
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        head = insertAtTail(head, d);
    }
    return head;
}

void print(node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    while (head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->prev;
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
    node* head;
    cin>>head;
    cout<<head;
    return 0;
}