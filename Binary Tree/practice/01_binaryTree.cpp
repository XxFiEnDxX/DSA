#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* build(){
    cout<<"ENter- ";
    int d;
    cin>>d;

    if (d == -1)
    {
        return NULL;
    }

    node* root = new node(d);
    root->left = build();
    root->right = build();
    
    return root;
}

void preOrder(node* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node* root){
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(node* root){
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int height(node* root){
    if (root  == NULL)
    {
        return 0;
    }
    
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}

void printKthlvl(node* root , int k){
    if (root == NULL)
    {
        return ;
    }
    if (k == 1)
    {
        cout<<root->data<<" ";
    }
    printKthlvl(root->left,k-1);
    printKthlvl(root->right,k-1);
}
void printAlllvl(node* root){
    int h = height(root);

    for (int i = 1; i <= h; i++)
    {
        printKthlvl(root,i);
        cout<<endl;
    }
    
}
int main()
{
    node* root = build();
    preOrder(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    printAlllvl(root);
    return 0;
}