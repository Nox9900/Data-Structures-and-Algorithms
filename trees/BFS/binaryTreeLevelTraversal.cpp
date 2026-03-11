#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            if(!root) return res;
            queue<TreeNode*> qt;
            qt.push(root);

            while(!qt.empty()) {
                int lv = qt.size();
                vector<int> level;
                for(int i=0; i<lv; i++) {
                    TreeNode* node = qt.front();
                    qt.pop();
                    level.push_back(node->val);

                    if(node->left) qt.push(node->left);
                    if(node->right) qt.push(node->right);
                }
                res.push_back(level);
            }
            return res;
        }
};