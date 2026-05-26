/*
    FIND ALL ANAGRAMS IN A STRING
    https://leetcode.com/problems/find-all-anagrams-in-a-string
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()) return res;

        vector<int> cnt(26, 0);
        for(char& c:p) {
            cnt[c - 'a']++;
        }

        int left=0, right=0, diff = p.size();
        while(right < s.size()) {
            if(cnt[s[right] - 'a'] >= 1) 
                diff--;
            cnt[s[right]-'a']--;
            right++;

            if(diff==0) res.push_back(left);

            if(right - left == p.size()) {
                if(cnt[s[left]-'a'] >= 0) diff++;
                cnt[s[left]-'a']++;
                left++;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int count=0;
        int l=0,r=0;
        int freq[26]={0};
        int m=p.size();
        vector<int>res;
        for(char c:p)
        {
            freq[c-'a']++;
            count++;
        }
        while(r<n)
        {
            if(freq[s[r]-'a']-->0)
            {
                count--;
            }
            while(count==0)
            {
                if(r-l+1==m)
                {
                    res.push_back(l);
                }
                
                if(++freq[s[l]-'a']>0)
                {
                    count++;
                }
                l++;
            }
            r++;
        }
        return res;
    }
};