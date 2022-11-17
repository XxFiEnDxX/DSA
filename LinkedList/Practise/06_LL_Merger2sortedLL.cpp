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

ostream& operator<<(ostream&op,node*head){
    print(head);
    return op;
}

istream& operator>>(istream&ip,node*&head){
    head = build();
    return ip;
}

node* merge(node* a ,node* b){
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node* c = NULL;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next , b);
    }else
    {
        c = b;
        c->next = merge(a , b->next);
    }
    return c;
}

int main()
{
    node* head1;
    node* head2; 
    cin>>head1>>head2;
    cout<<head1<<head2;

    cout<<merge(head1,head2);
    return 0;
}