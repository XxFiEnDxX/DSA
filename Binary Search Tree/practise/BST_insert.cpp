#include <iostream>
#include<queue>
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
void printIn(node* root){
    if (root == NULL)
    {
        return;
    }

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);    
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << q.front()->data << " ";
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
}

node *build()
{
    int c;
    cin >> c;
    node*root = NULL;
    while (c != -1)
    {
        root = insertInBST(root, c);
        cin >> c;
    }
    return root;
}

int main()
{
    node *root = build();
    // printIn(root);
    bfs(root);
    return 0;
}