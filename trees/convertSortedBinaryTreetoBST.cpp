/*
    CONVERT BINARY TREE TO BINARY SEARCH TREE
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
*/


class Solution {
public:
    TreeNode* BST(vector<int> nums, int left, int right) {
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = BST(nums, left, mid-1);
        newNode->right = BST(nums, mid+1, right);
        return newNode;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size()-1);
    }
};


class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if(st>end){
            return NULL;
        }
        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};