#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;
    if (d == -1)
    {
        return NULL;
    }
    
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

int count(node* head){
    if(head == NULL){
        return 0;
    }

    int left = count(head->left);
    int right = count(head->right);
    return left+right+1;
}

int Sum(node* head){
    if(head == NULL){
        return 0;
    }

    int left = Sum(head->left);
    int right = Sum(head->right);
    return left+right+head->data;
}


int main()
{
    node* root = buildTree();
    cout<<count(root)<<endl;
    cout<<Sum(root)<<endl;
    return 0;
}