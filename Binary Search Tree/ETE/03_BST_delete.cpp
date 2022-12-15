#include <iostream>
#include <bits/stdc++.h>
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

node *insertInBST(node *root, int d)
{
    if (root == NULL)
    {
        return new node(d);
    }

    else if (root->data > d)
    {
        root->left = insertInBST(root->left, d);
    }

    else if (root->data < d)
    {
        root->right = insertInBST(root->right, d);
    }

    return root;
}

node *build()
{
    int d;
    cin >> d;

    node *root = NULL;

    while (d != -1)
    {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

void preOrder(node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

node *deleteInBST(node *root, int d)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > d)
    {
        root->left = deleteInBST(root->left, d);
    }
    else if (root->data == d)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right != NULL && root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else{
            node* replace = root->right;
            while (replace->left)
            {
                replace = replace->left;
            }
            
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            return root;
        }
    }
    else
    {
        root->right = deleteInBST(root->right, d);
    }
    return root;
}

int main()
{
    node *root = build();
    root = deleteInBST(root,3);
    preOrder(root);
    return 0;
}