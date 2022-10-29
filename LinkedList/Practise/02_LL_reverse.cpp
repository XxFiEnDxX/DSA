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

void insertAtHead(node*&head, int d){
    if (head == NULL)
    {
        head = new node(d);
        return ;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
}
void insertAtTail(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return ;
    }
    node* temp  = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(d);
}
node* build(){
    int n;
    cin>>n;
    node* head = NULL;
    while (n != -1)
    {
        insertAtTail(head,n);
        cin>>n;
    }
    return head;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<"-> ";
        head = head->next;
    }
    cout<<endl;
}

void reverse(node*&head){
    node* c = head;
    node* p = NULL;
    node* n = c->next;
    while (c != NULL)
    {
        c->next = p;

        p = c;
        c = n;
        n = c->next;
    }
    head = p;
}
ostream& operator<<(ostream&op,node*head){
    print(head);
    return op;
}

istream& operator>>(istream&ip,node*&head){
    head = build();
    return ip;
}

int main()
{
    node* head1;
    cin>>head1;       //input

    cout<<head1;      //output before reverse
    reverse(head1);
    cout<<head1;      //outpur after reverse

    return 0;
}