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
        root = insertInBST(root,d);
        cin >> d;
    }
    return root;
}   

class LinkedList{
    public:
    node*head;
    node*tail;
};

LinkedList flatten(node* root){
    LinkedList l;

    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }
    //leaf node
    if (root->left == NULL && root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    //left in Not Null
    if (root->left != NULL && root->right == NULL)
    {
        LinkedList leftll = flattern(root->left);
        leftll.tail->right= root;
    }
    if (root->left == NULL && root->right != NULL)
    {
        /* code */
    }
    
    
    
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

int main()
{
    node* root = buildTree();
    PrintInorder(root);
    return 0;
}