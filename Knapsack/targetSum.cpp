#include<vector>

/*
    TARGET SUM
    https://leetcode.com/problems/target-sum/

*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int& num : nums ) sum += num;

        if((target+sum)%2 != 0 || target+sum < 0) {
            return 0;
        }

        int sub = (target+sum)/2;
        vector<int> dp(sub+1, 0);
        dp[0] = 1;

        for(int& num : nums) {
            for(int s = sub; s>=num; s--) {
                dp[s] += dp[s-num]; 
            }
        }

        return dp[sub];
    }
};