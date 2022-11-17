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
node* midPoint(node*head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* kthnodeFromEnd(node* head, int k){
    node* slow = head;
    node* fast = head;
    for (int i = 0; i < k; i++)
    {  
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

bool CycleDetection(node* head){
    node* slow = head;
    node* fast = head;
    while (fast!= NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    while (fast!= NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            slow = head;
            break;
        }
    }
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}
int main()
{
    // node* head = build();
    // print(head);

    node* head1 = NULL;
    node* head2 = NULL;
    cin>>head1>>head2;
    cout<<head1;

    node* k = kthnodeFromEnd(head1,5);
    node* temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = k;

    cout<<CycleDetection(head1)<<endl;
    removeCycle(head1);
    cout<<CycleDetection(head1)<<endl;
    // cout<<CycleDetection(head2)<<endl;
    // cout<<midPoint(head1)->data;
    return 0;
}