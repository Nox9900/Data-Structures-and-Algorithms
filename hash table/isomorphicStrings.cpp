/*
    ISOMORPHIC STRINGS
    https://leetcode.com/problems/isomorphic-strings
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        char mappedS[256] = {0};
        char mappedT[256] = {0};
    
        for(int i=0; i<s.size(); i++) {
            char ms = s[i];
            char ts = t[i];
            
            if(mappedS[ms] ==0 && mappedT[ts] ==0) {
                mappedT[ts] = ms;
                mappedS[ms] = ts;
            } else if(mappedT[ts] != ms || mappedS[ms] != ts) return false;
        }
        return true;
    }
};