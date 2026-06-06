/*
    MAXIMUN PRODUCT ARRAY
    https://leetcode.com/problems/maximum-product-subarray/description/

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int max_c = nums[0], min_c = nums[0];
            int maxSum = nums[0];
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] < 0) swap(min_c, max_c);
                max_c = max(nums[i], max_c*nums[i]);
                min_c = min(nums[i], min_c*nums[i]);
                maxSum = max(maxSum, max_c);
            }

            return maxSum;
        }
};