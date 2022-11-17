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

node *BuildTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

void printIn(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
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
void Printkthlvl(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    Printkthlvl(root->left, k - 1);
    Printkthlvl(root->right, k - 1);
    return;
}

void printAlllvl(node* root){
    int h = height(root);

    for (int i = 1; i <= h; i++)
    {
        Printkthlvl(root,i);
        cout<<endl;
    }
    
}
int main()
{
    node *root = BuildTree();
    printIn(root);

    cout << endl;
    cout << "Height of the tree is " << height(root) << endl;
    printAlllvl(root);
    //Time complexity is n^2;
    return 0;
}