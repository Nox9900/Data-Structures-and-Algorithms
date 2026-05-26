/*
    PERMUTATION IN STRING
    https://leetcode.com/problems/permutation-in-string
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
         bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> s1cnt(26, 0);
        vector<int> s2cnt(26, 0);

        for(int i=0; i<s1.size(); i++) {
            s1cnt[s1[i]-'a']++;
            s2cnt[s2[i]-'a']++;
        }

        if(s1cnt == s2cnt) return true;
        
        for(int i=s1.size(); i<s2.size(); i++) {
            s2cnt[s2[i] - 'a']++;
            s2cnt[s2[i - s1.size()] - 'a']--;
            if (s1cnt == s2cnt) return true;
        }
        return false;
    }
};