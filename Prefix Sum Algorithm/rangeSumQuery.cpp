/*
    RANGE SUM QUERY
    https://leetcode.com/problems/range-sum-query-immutable
*/

#include<bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());
        prefix[0] = nums[0];
        for(int i=0; i<nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    int rangeQuery(int left, int right) {
        if(left==0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }

};