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
        left = NULL;
        right = NULL;
    }
};

node* BuildTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    node* root = new node(data);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

void print(node* root){
    if (root == NULL)
    {
        return;
    }
    print(root->left); 
    print(root->right); 
    cout<<root->data<<" ";
}

int main()
{
    node* root = BuildTree();
    print(root);
    return 0;
}