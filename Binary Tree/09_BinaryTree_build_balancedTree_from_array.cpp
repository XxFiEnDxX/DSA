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
node *build(int *a, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    node *root = new node(a[mid]);

    root->left = build(a, s, mid - 1);
    root->right = build(a, mid + 1, e);
    return root;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    node *root = build(a, 0, n - 1);

    bfs(root);
    // printIn(root);

    return 0;
}