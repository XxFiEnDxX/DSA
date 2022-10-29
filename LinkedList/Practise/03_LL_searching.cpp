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

bool searching(node* head, int k){
    while (head)
    {
        if (head->data == k)
        {
            return true;
        }
        head = head->next;
    }
    return false; 
}

int main()
{
    // node* head = build();
    // print(head);

    node* head1;
    node* head2;
    cin>>head1>>head2;
    cout<<head1<<head2;

    cout<<searching(head1,40);
    return 0;
}