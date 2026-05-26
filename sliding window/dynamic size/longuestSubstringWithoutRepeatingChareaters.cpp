/*
    LONGUEST SUBSTRING WITHOUT REPEATING CHARACTERS
    https://leetcode.com/problems/longest-substring-without-repeating-characters
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> res;
        int l=0, cnt=0;
        
        // If character already seen and in current window
        for(int r=0; r<s.size(); r++) {
            if(res.find(s[r]) != res.end()) //Move left pointer past duplicate
                l = max(res[s[r]]+1, l);

            res[s[r]] = r; // Update/insert character's latest index
            cnt = max(cnt, r-l+1); // Update max length
        }
        return cnt;
    }
};