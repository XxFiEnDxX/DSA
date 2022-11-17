#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    pair<TreeNode*,TreeNode*> convertLL(TreeNode* root){
        pair<TreeNode*,TreeNode*> p;
        if(!root->left && !root->right){
            p.first = root;
            p.second = root;
            return p;
        }
        if(root->left != NULL && !root->right){
            pair<TreeNode*,TreeNode*> ls = convertLL(root->left);
            
            ls.second->right = root;
            
            p.first = ls.first;
            p.second = root;
            return p;
        }
        if(!root->left && root->right!=NULL){
            pair<TreeNode*,TreeNode*> rs = convertLL(root->right);
            
            root->right = rs.first;
            
            p.first = root;
            p.second = rs.second;
            return p;
        }

        pair<TreeNode*,TreeNode*> ls = convertLL(root->left);
        pair<TreeNode*,TreeNode*> rs = convertLL(root->right);
        
        ls.second->right = root;
        root->right = rs.first;
        
        p.first = ls.first;
        p.second = rs.second;
        
        return p;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        pair<TreeNode*,TreeNode*> p = convertLL(root);
        
        TreeNode* temp = p.first;
        
        return temp;;
    }
};

int main()
{

}