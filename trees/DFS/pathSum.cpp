/*
    PATH SUM III
    https://leetcode.com/problems/path-sum-iii 
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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> sum;
        sum[0] = 1;
        return dfs(root, 0, targetSum, sum);
    }
private:
    int dfs(TreeNode* node, long long currSum, int targetSum, unordered_map<long long, int> sum) {
        if(node == nullptr) return 0;
        currSum += node->val;
        int numPathToCurr = sum[currSum - targetSum];
        sum[currSum]++;
        int result = numPathToCurr + dfs(node->left, currSum, targetSum, sum)+ dfs(node->right, currSum, targetSum,sum);
        sum[currSum]--;
        return result;
    }
};


//optimal solution
class Solution2 {
public:
int dfs(TreeNode* root, long long  currsum, int targetSum, unordered_map<long long,int>&mp){
    if(!root) return 0;
    int count=0;
    currsum+=root->val;
    if(mp.find(currsum-targetSum)!=mp.end()){
        count+=mp[currsum-targetSum];
    }
    mp[currsum]++;
    count+=dfs(root->left, currsum, targetSum, mp);
    count+=dfs(root->right, currsum, targetSum, mp);
    mp[currsum]--;
    return count;
}
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>mp;
        mp[0]=1;
        return dfs(root, 0, targetSum, mp);
    }
};