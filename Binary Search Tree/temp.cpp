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
    if (d < root->data)
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

void PrintInorder(node* root){
    if (root == NULL)
    {
        return;
    }
    PrintInorder(root->left);
    cout<<root->data<<" ";   
    PrintInorder(root->right);
}
void PrintPreorder(node* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";   
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}
void PrintPostorder(node* root){
    if (root == NULL)
    {
        return;
    }
    PrintPostorder(root->left);
    PrintPostorder(root->right);
    cout<<root->data<<" ";   
}

bool search(node* root, int d){
    if (root == NULL)
    {
        return false;
    }
    if (d == root->data)
    {
        return true;
    }
    
    if (d<root->data)
    {
        return search(root->left,d);
    }else
    {
        return search(root->right,d);
    } 
}
int main()
{
    node *root = buildTree();

    cout<<"PreOrder- ";
    PrintPreorder(root);
    cout<<endl;
    cout<<"Inorder- ";
    PrintInorder(root);
    cout<<endl;
    cout<<"PostOrder- ";
    PrintPostorder(root);

    int s;
    cin>>s;
    if (search(root,s))
    {
        cout<<"Present!"<<endl;
    }else
    {
        cout<<"Not Present!"<<endl;
    }
    return 0;    
}