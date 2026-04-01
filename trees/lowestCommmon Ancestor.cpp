#include<bits/stdc++.h>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root==p || root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != nullptr && right != nullptr) return root;
        return left != nullptr ? left : right;
    }
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val|| root->val==q->val){
            return root;
        }
        TreeNode* ll= lowestCommonAncestor(root->left,p,q);
        TreeNode* rl= lowestCommonAncestor(root->right,p,q);
        if(ll && rl ){
            return root;
        }
        else if(ll!=NULL && rl==NULL){
            return ll;
        }
        else{
            return rl;
        }
    }
};