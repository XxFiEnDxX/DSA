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

node* buildTree(int *in,int *pre, int s, int e){
    static int i = 0;
    if (s>e)
    {
        return NULL;
    }

    node* root = new node(pre[i]);

    int index = -1;

    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
        }
    }
        
        i++;
        root->left = buildTree(in,pre,s,index-1);
        root->right = buildTree(in,pre,index+1,e);

        return root;
}
int main()
{
    int n = 7;

    int pre[n] = {5,2,1,3,7,6,8};
    int in[n] = {1,2,3,5,6,7,8};

    node *root = buildTree(in,pre,0,n-1);

    bfs(root);


    return 0;
}