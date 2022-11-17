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

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = count(root->left);
    int rs = count(root->right);
    return ls+rs+1;
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
    cout<<"Total No. of Nodes "<<count(root)<<endl;
    cout<<"Sum of all the Nodes "<<SumofNodes(root);
    return 0;
}