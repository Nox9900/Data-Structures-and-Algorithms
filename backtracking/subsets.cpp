/*
    SUBSETS
    https://leetcode.com/problems/subsets

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
  vector<vector<int>>ans;
private:
    void sub(int ind,vector<int>& cur,vector<int>& nums){
        if(ind==nums.size()){
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[ind]);
        sub(ind+1,cur,nums);
        cur.pop_back();
        sub(ind+1,cur,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        sub(0,cur,nums);
        return ans;
    }
};