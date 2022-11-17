#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

node* insertAtTail(node*head,int d){
        if (head == NULL)
        {
            node* n = new node(d);
            n->next = n;
            return n;
        }
        node* temp = head;
        while (temp->next!=head)
        {
            temp = temp->next;
        }
        node* n = new node(d);
        temp->next = n;
        n->next = head;
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
    node*temp=head;
    while (temp->next != head)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
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