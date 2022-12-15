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

int height(node* head){
    if (!head)
    {
        return 0;
    }

    int ls = height(head->left);
    int rs = height(head->right);
    
    return max(ls,rs)+1;
}

void printkthLVL(node* head,int h){
    if (!head)
    {
        return ;
    }
    
    if (h == 0)
    {
        cout<<head->data<<" ";
        return;
    }

    printkthLVL(head->left,h-1);
    printkthLVL(head->right,h-1);
}

void printAllLVl(node* head){
    int h = height(head);

    for (int i = 0; i < h; i++)
    {
        printkthLVL(head,i);
    }
}

int main()
{
    node* head = build();
    // preOrder(head);

    printAllLVl(head);
    return 0;
}