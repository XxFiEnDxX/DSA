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

void preOrder(node* root){
    if (!root)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* node = q.front();
        q.pop();

        cout<<node->data<<" ";

        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
    }
    
}

int main()
{
    node *root = build();

    // preOrder(root);
    bfs(root);
    return 0;
}