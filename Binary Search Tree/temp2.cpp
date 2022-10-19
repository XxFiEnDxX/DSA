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

bool search(node* root, int d){
    if (root == NULL)
    {
        return false;
    }
    if (d == root->data)
    {
        return true;
    }
    if(d<root->data){
        return search(root->left,d);
    }
    else{
        return search(root->right,d);
    }
}

node *buildTree()
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

void printInorder(node*root){
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" "; 
    printInorder(root->right);
    
}
int main()
{
    node *root = buildTree();

    printInorder(root);

    int s;
    cin>>s;
    if (search(root,s))
    {
        cout<<"Present!"<<endl;
    }else{
        cout<<"Not present!"<<endl;
    }
    
    return 0;
}