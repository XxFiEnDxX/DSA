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

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            cout<<endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        
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

int sumReplace(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    
    int ls = sumReplace(root->left);
    int rs = sumReplace(root->right);

    int old = root->data;
    root->data = ls + rs;

    return old+root->data;
}

int main()
{
    node *root = build();
    // bfs(root);
    cout<<endl;
    sumReplace(root);
    bfs(root);
    return 0;
}
