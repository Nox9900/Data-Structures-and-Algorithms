#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end()); // O(n logn) for sorting
        
        int longuest=1, curr=1;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                if(nums[i] == nums[i-1]+1) 
                    curr++;
                else {
                    longuest = max(longuest, curr);
                    curr=1;
                }
            }
        } 
        return max(longuest, curr);
    }
};

// optimal solution using hash set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int maxCount = 0;

        for (int num : s) {
            // Start only when it's the beginning of a sequence
            if (!s.count(num - 1)) {
                int currentNum = num;
                int count = 1;

                // Count the consecutive sequence
                while (s.count(currentNum + 1)) {
                    currentNum++;
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};
