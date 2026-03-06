#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int maxSubaray(vector<int> nums) {
            int c = nums[0];
            int maxSum = nums[0];
            for(int i=1; i<nums.size(); i++) {
                c = max(c, c+nums[i]);
                maxSum = max(maxSum, c);
            }
            return maxSum;
        }
};