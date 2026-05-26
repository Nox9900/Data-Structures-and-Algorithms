/*
    VALIDATE BINARY SEARCH TREE
    https://leetcode.com/problems/validate-binary-search-tree
*/

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
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

    bool validate(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if((minNode != nullptr && root->val <= minNode->val) ||
            (maxNode != nullptr && root->val >= maxNode->val)) {
                return false;
            }
        return validate(root->left, minNode, root) && validate(root->right, root, maxNode);
    }
};