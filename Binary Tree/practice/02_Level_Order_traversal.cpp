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

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}

void printKthlvl(node* root,int k){
    if(root == NULL){
        return ;
    }
    if(k == 1){
        cout<<root->data<<" ";
    }
    printKthlvl(root->left,k-1);
    printKthlvl(root->right,k-1);
    return ;
}

void printAllLvl(node* root){
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printKthlvl(root,i);
        cout<<endl;
    }
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


int main()
{
    node* root = buildTree();
    // cout<<height(root)<<endl;
    // preorder(root);
    printAllLvl(root);
    return 0;
}