#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int c_max = nums[0], c_min=nums[0];
            int maxSum = nums[0];

            for(int i=0; i<nums.size(); i++) {
                if(nums[i] < 0) swap(c_max, c_min);
                c_max = max(nums[i], c_max*nums[i]);
                c_min = min(nums[i], c_min*nums[i]);
                maxSum = max(maxSum, c_max);
            }
            return maxSum;
        }
};

