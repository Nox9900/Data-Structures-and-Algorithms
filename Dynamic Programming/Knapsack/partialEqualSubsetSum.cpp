#include<vector>


/*
    PARTITION EQUAL SUBSET SUM
    https://leetcode.com/problems/partition-equal-subset-sum/
*/


class Solution {
public:

    bool canPartition(vector<int>& nums) {
        /*
        Divide the array into two parts such that the sum of elements in both 
        the arrays is equal.
        Find a subset of the array such that the sum of elements is half the 
        total sum of the elements of the array.
        */

        int totalSum = 0;
        for (int num : nums) totalSum += num;
        if (totalSum % 2 == 1) return false;
        int target = totalSum / 2;
        vector<int> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
            if (dp[target]) return true;
        }
        return dp[target];
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {int sum = 0;
    int n = nums.size();
    for(int i: nums)
     sum += i;

    if(sum%2 == 1)
     return false;
     
    int target = sum/2;
   
    bitset<10001> bits(1);
    for(int i : nums)
        bits = bits | (bits << i);
        
    return bits[target];
    }
};