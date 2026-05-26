/*
    CONTAINER WITH THE MOST WATER
    https://leetcode.com/problems/container-with-most-water
*/

#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int  left=0 ,right=height.size() - 1;
        int maxArea = 0;
        while(left<right) {
            int minArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, minArea);
            if(height[left]<height[right]) left++;
            else right--;
            
        }
        return maxArea;
    }
};