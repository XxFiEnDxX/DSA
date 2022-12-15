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

node* build(){
    int d;
    cin>>d;
    if (d == -1)
    {
        return NULL;
    }

    node* head = new node(d);
    
    head->left = build();
    head->right = build();
    return head;
}

void preOrder(node* head){
    if (!head)
    {
        return;
    }
    cout<<head->data<<" ";
    preOrder(head->left);
    preOrder(head->right);
    return;
}

pair<int,int> diameter(node* head){
    pair<int,int> p;
    if (!head)
    {
        return {0,0};
    }
    
    pair<int,int> ls = diameter(head->left);
    pair<int,int> rs = diameter(head->right);

    p.first = max(ls.first,rs.first)+1;
    p.second = max(ls.first+rs.first,max(ls.second,rs.second));
    return p;
}

int main()
{
    node* head = build();
    // preOrder(head);

    cout<<diameter(head).second;
    return 0;
}