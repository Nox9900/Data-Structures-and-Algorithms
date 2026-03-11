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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> qt;
        qt.push(root);

        while(!qt.empty()) {
            int level = qt.size();
            TreeNode* node = nullptr;

            for(int i=0; i<level; i++) {
                node = qt.front();
                qt.pop();

                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
            if(node) res.push_back(node->val);
        }
        return res;

    }
};