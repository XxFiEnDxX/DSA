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
    else if (d < root->data)
    {
        root->left = insertInBST(root->left, d);
    }
    else
    {
        root->right = insertInBST(root->right, d);
    }
    return root;
}

node *buildBST()
{
    int n;
    cin >> n;

    node *root = NULL;

    while (n != -1)
    {
        root = insertInBST(root, n);
        cin >> n;
    }
    return root;
}

void printInOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

node *deleteInBST(node *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (k < root->data)
    {
        root->left = deleteInBST(root->left, k);
        return root;
    }
    else if (root->data == k)
    {
        // 1st case
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 2nd case
        else if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 3rd case
        else
        {
            node *replace = root->right;
            while (replace->left != NULL)
            {
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right, replace->data);
            return root;
        }
    }
    else
    {
        root->right = deleteInBST(root->right, k);
        return root;
    }
}
int main()
{
    node *root = buildBST();
    printInOrder(root);
    root = deleteInBST(root, 4);
    cout << endl;
    printInOrder(root);
    return 0;
}