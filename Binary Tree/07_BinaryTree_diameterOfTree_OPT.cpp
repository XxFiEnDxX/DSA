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

pair<int,int> fastDiameter(node* root){
    pair<int,int> p;
    if (root == NULL)
    {
        p.first = p.second = 0;
        return p;
    }
    pair<int,int> ls = fastDiameter(root->left);
    pair<int,int> rs = fastDiameter(root->left);
    
    p.first = max(ls.first,rs.first)+1;
    p.second = max((ls.first+rs.first),max(ls.second,rs.second));
    
    return p;
}

int main()
{
    node *root = build();
    cout<<fastDiameter(root).first<<endl;
    cout<<fastDiameter(root).second; //n^2 time complexity
  
    return 0;
}