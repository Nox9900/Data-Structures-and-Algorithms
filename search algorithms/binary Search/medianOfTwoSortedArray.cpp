

/*
    MEDIAN OF TWO SORTED ARRAY
    https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int left=0, right = m;
        int half = (m+n+1) / 2;

        while(left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i;

            int maxLeft = (i==0) ? INT_MIN : nums1[i-1];
            int minRight = (i==m) ? INT_MAX : nums1[i];
            int maxLeft1 = (j==0) ? INT_MIN : nums2[j-1];
            int minRight1 = (j==n) ? INT_MAX : nums2[j];
        
            if(maxLeft <= minRight1 && maxLeft1 <= minRight) {
                if((m+n)%2 == 1)
                    return max(maxLeft, maxLeft1);
                return (max(maxLeft, maxLeft1) + min(minRight, minRight1)) / 2.0;
            } else if(maxLeft > minRight1) {
                right = i-1;
            }else {
                left = i+1;
            }
        }
        return 0.0;
    }
};