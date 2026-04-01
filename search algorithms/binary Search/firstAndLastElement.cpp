#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstPosition(nums, target), lastPosition(nums, target)};
    }

    int firstPosition(vector<int> nums, int target) {
        int n = nums.size(), left=0, right=n-1;
        int firstPosition=-1;
        while(left<=right) {
            int mid= left+(right-left)/2;
            if(nums[mid]==target){
                firstPosition = mid;
                right = mid-1;
            } 
            else if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }

        return firstPosition;
    }

    int lastPosition(vector<int> nums, int target) {
        int n = nums.size(), left=0, right=n-1;
        int lastPosition=-1;
        while(left<=right) {
            int mid= left+(right-left)/2;
            if(nums[mid]==target){
                lastPosition = mid;
                left = mid+1;
            } 
            else if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
        return lastPosition;
    }
};