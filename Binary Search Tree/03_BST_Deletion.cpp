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

node *insertInBST(node *root, int d)
{
    if (root == NULL)
    {
        return new node(d);
    }
    if (d <= root->data)
    {
        root->left = insertInBST(root->left, d);
    }
    else
    {
        root->right = insertInBST(root->right, d);
    }
    return root;
}

node *buildTree()
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

void PrintInorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    PrintInorder(root->left);
    cout << root->data << " ";
    PrintInorder(root->right);
}

bool search(node *root, int d)
{
    if (root == NULL)
    {
        return false;
    }
    if (d == root->data)
    {
        return true;
    }
    if (d <= root->data)
    {
        return search(root->left, d);
    }
    else
    {
        return search(root->right, d);
    }
}

node *deleteInBST(node *root, int d)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (d < root->data)
    {
        root->left = deleteInBST(root->left, d);
        return root;
    }
    else if (d == root->data)
    {
        // case 1
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case 2
        else if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        //case 3
        else
        {
            node* replace = root->right;
            while (replace->left != NULL)
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
        return root;
    }
}

int main()
{
    node *root = buildTree();
    PrintInorder(root);

    int d;
    cin>>d;

    root = deleteInBST(root,d);
    cout<<endl;
    PrintInorder(root);
    cout<<endl;

    return 0;
}