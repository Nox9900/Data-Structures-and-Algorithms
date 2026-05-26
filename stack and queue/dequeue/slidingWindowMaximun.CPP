/*
    MAX SLIDING WINDOW
    https://leetcode.com/problems/sliding-window-maximum
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return {};

        deque<int> dq;
        vector<int> res(nums.size() - k + 1);
        for(int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1) {
                res[i - k + 1] = nums[dq.front()];
            }
        }

        return res;
    }
};