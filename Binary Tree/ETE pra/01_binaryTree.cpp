#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node* build(){
    int d;
    cin>>d;
    if (d == -1)
    {
        return NULL;
    }

    node* head = new node(d);
    
    head->left = build();
    head->right = build();
    return head;
}

void preOrder(node* head){
    if (!head)
    {
        return;
    }
    cout<<head->data<<" ";
    preOrder(head->left);
    preOrder(head->right);
    return;
}

int main()
{
    node* head = build();
    preOrder(head);
    return 0;
}