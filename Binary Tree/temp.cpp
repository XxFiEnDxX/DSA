#include<iostream>
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

node *build()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = build();
    root->right = build();

    return root;
}

int SumOfNodes(node* root){
    if (root == NULL)
    {
        return 0;
    }
    
    int ls = SumOfNodes(root->left);
    int rs = SumOfNodes(root->right);

    return ls+rs+root->data;
}

int main()
{
    node* root = build();
    cout<<SumOfNodes(root);
    return 0;
}