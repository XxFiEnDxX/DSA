#include <iostream>
#include <queue>
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
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    int op1 = ls + rs;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);    
    return max(op1,max(op2,op3));
}
int SumofNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = SumofNodes(root->left);
    int rs = SumofNodes(root->right);
    return ls+rs+root->data;
}
int main()
{
    node *root = build();
    cout<<diameter(root);
  
    return 0;
}