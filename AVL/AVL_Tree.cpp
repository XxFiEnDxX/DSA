#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
    int height = 0;
    node(int x){
        val = x;
        left = right = NULL;
        height = 1;
    }
};

int height(node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int getBalanced(node* root){
    if(root == NULL)return 0;
    return height(root->left)-height(root->right);
}

node* leftRotation(node* y){
    node* x = y->right;
    node* t2 = x->left;

    //perform rotation.
    x->left = y;
    y->right = t2;

    //update height.
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    
    return x;
}

node* rightRotation(node* y){
    node* x = y->left;
    node* t2 = x->right;

    //perform rotation.
    x->right = y;
    y->left = t2;

    //update height.
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    
    return x;
}

node* insertion(node* root, int key){
    if(root == NULL)return new node(key);
    
    if(key < root->val){
        root->left = insertion(root->left,key);
    }
    else if (key > root->val)
    {
        root->right = insertion(root->right,key);
    }
    else
    {
        return root;
    }

    root->height = max(height(root->left),height(root->right))+1;

    int bal = getBalanced(root);

    // LL
    if(bal > 1 && key < root->left->val){
        return rightRotation(root);
    }
    // RR
    if(bal < -1 && key > root->right->val){
        return leftRotation(root);
    }
    // LR
    if(bal > 1 && key > root->left->val){
        root->left = leftRotation(root->left); 
        return rightRotation(root);
    }
    // RL
    if(bal < -1 && key < root->right->val){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}


void preorder(node* root){
    if(root == NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void preHeight(node* root){
    if(root == NULL)return;
    cout<<root->height<<" ";
    preHeight(root->left);
    preHeight(root->right);
    return;
}
void postorder(node* root){
    if(root == NULL)return;
    postorder(root->left);
    cout<<root->val<<" ";
    postorder(root->right);
    return;
}

int main()
{
    int n;cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }

    node* root = NULL;
    for(auto ele:arr){
        root = insertion(root,ele);
    }
    
    preorder(root);
    cout<<endl;
    // preHeight(root);
    cout<<endl;
    // postorder(root);
    return 0;
}

//7
//80 100 140 40 20 60 120