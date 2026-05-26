/*
    BINARY TREE IN-ORDER TRAVERSAL
    https://leetcode.com/problems/binary-tree-inorder-traversal
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

    void inorderOutput(TreeNode* p, vector<int>& result) {
        if(!p) return;
        inorderOutput(p->left, result);
        result.push_back(p->val);
        inorderOutput(p->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        inorderOutput(root, result);
        return result;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
          while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }

        return result;
    }
};