/*
    TWO SUM II - INPUT ARRAY IS SORTED
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> twosum(vector<int>& number, int  target) {
            int n = number.size(), right=n-1, left=0;
            while(left<right) {
                int s = number[left] + number[right];
                if(s==target) return {left+1, right+1};
                if(s>target) right--;
                else left++;
            }
            return {};
        }
};