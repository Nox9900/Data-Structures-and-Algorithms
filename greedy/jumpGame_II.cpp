#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int j=0, maxReach=0, currEnd=0;
        for(int i=0; i<nums.size()-1; i++) {
            maxReach = max(maxReach, i+nums[i]);
            if(i == currEnd) {
                j++;
                currEnd = maxReach;
            }
            if(currEnd >= nums.size()-1) {
                return j;
            }
        }
        return j;
    }
};