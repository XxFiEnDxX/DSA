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

void bfs(node *root)
{
    queue<node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        int levelSize = q.size();  // Process nodes level by level
        for (int i = 0; i < levelSize; ++i) 
        {
            node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) 
            {
                q.push(current->left);
            }
            if (current->right) 
            {
                q.push(current->right);
            }
        }
        cout<<endl; // Print a new line after processing each level
    }
}
int main()
{
    node *root = build();
    bfs(root);  
    return 0;
}