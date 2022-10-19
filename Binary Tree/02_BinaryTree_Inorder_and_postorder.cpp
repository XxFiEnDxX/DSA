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

void printIn(node* root){ 
    if (root == NULL)
    {
        return;
    }
    printIn(root->left); 
    cout<<root->data<<" ";
    printIn(root->right); 
}

int main()
{
    node* root = BuildTree();
    printIn(root);
    return 0;
}