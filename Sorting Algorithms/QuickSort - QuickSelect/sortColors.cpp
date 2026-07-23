/*
    SORT COLORS
    https://leetcode.com/problems/sort-colors
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0, cnt1=0, cnt2=0;
        for(int& num:nums) {
            if(num==0) cnt0++;
            else if(num==1) cnt1++;
            else cnt2++;
        }

        int index=0;
        while(cnt0-- > 0) nums[index++] =0;
        while(cnt1-- > 0) nums[index++] =1;
        while(cnt2-- > 0) nums[index++] =2;
    }
};