#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtracking(nums, result, temp, used);
        return result;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, vector<bool>& used) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
        } else {
            for(int i=0; i<nums.size(); i++) {
                if(used[i]) continue;

                used[i] = true;
                temp.push_back(nums[i]);
                backtracking(nums, result, temp, used);
                used[i]=false;
                temp.pop_back();
            }
        }
    }
};