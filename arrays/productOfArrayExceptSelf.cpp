/*
    PRODUCT OF ARRAY EXCEPT SELF
    https://leetcode.com/problems/product-of-array-except-self
*/


#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int cur = 1;
        for (int i = n - 2; i >= 0; i--) {
            res[i] = res[i] * cur * nums[i + 1];
            cur = cur * nums[i + 1];
        }
        return res;
    }
};