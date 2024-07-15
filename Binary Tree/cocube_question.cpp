// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    int h = 0; // for storing the depth of that node from the root.. so we dont need to calculate again and again.
    // it will help for finding the distance between the two node.
    Node* left = NULL;
    Node* right = NULL;
    Node(int it){
        val = it;
    }
};

// for printing the preorder
void preOrder(Node* root){
    if(root == NULL)return ;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
// for print the depth of the nodes in preOrder fashion
void hOrder(Node* root){
    if(root == NULL)return ;
    cout<<root->h<<" ";
    hOrder(root->left);
    hOrder(root->right);
}

// This function will return the distance(edges) between the 2 leaf node 'a' and 'b'
void findAllLeaf(Node* root, vector<int> &leafNode){
    if(root == NULL)return ;
    if(root->left == NULL && root->right == NULL){
        leafNode.push_back(root->val);
        return;
    }

    findAllLeaf(root->left,leafNode);
    findAllLeaf(root->right,leafNode);
}

int distanceBtwLeafNode(Node* root, int a, int b){
    if(root == NULL)return -1;
    else if(root->val == a || root->val == b){
        return root->h;
    }
    int ls = distanceBtwLeafNode(root->left,a,b);
    int rs = distanceBtwLeafNode(root->right,a,b);

    if(ls != -1 && rs != -1){
        int dis = (ls-root->h)+(rs-root->h);
        return dis;
    }
    if(ls == -1)return rs;
    return ls;
}

int main() {
    int k;
    cin>>k;
    // k = 4;
    int h;
    cin>>h;
    // h = 3;
    
    queue<Node*> q;
    int ele;
    cin>>ele;
    Node* root = new Node(ele);
    // taking input
    q.push(root);
    for(int i = 1; i < h; i++){
        int size = q.size();
        while(size--){
            Node* cur = q.front();
            q.pop();
            
            int child;
            cin>>child;
            if(child != -1){
                cur->left = new Node(child);
                cur->left->h = i;
                q.push(cur->left);
            }
            cin>>child;
            if(child != -1){
                cur->right = new Node(child);
                cur->right->h = i;
                q.push(cur->right);
            }
        }
    }
    // preOrder(root);
    // cout<<endl;
    // hOrder(root);
    // cout<<endl;

    // find all the leaf node in our BT and storing it in a vector
    vector<int> leafNode;
    findAllLeaf(root,leafNode);
    for(int ele:leafNode){
        cout<<ele<<" ";
    }


    // for storing all the distance <= k between all possible two leaf node
    int ans = 0;
    for(int i = 0; i < leafNode.size(); i++){
        for(int j = i+1; j < leafNode.size(); j++){
            int dis = distanceBtwLeafNode(root,leafNode[i],leafNode[j]);
            cout<<dis<<" ";
            if(dis <= k){
                ans++;
            }
        }
    }
    cout<<endl<<ans<<" ";
    return 0;
}