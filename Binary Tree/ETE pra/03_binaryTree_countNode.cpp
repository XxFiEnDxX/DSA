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

int countN(node* head){
    if (!head)
    {
        return 0;
    }

    int ls = countN(head->left);
    int rs = countN(head->right);
    
    return ls+rs+1;
}

int main()
{
    node* head = build();
    // preOrder(head);

    cout<<countN(head);
    return 0;
}