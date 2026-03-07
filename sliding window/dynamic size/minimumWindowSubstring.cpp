#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tfreq;
        unordered_map<char, int> wfreq;

        for(char c:t) tfreq[c]++;
        int left =0, right=0;
        int matched = 0;
        int minL = 1e9;
        int start = 0;

        while(right < s.size()) {
            char c = s[right];
            wfreq[c]++;

            if(tfreq.count(c) && wfreq[c] == tfreq[c]) {
                matched++;
            }

            while(matched == tfreq.size()) {
                if(right - left + 1 < minL) {
                    minL = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                if(wfreq.count(leftChar)) {
                    wfreq[leftChar]--;
                    if(tfreq.count(leftChar) && wfreq[leftChar] < tfreq[leftChar])
                        matched--;
                }
                left++;
            }
            right++;
        }
        return (minL == (int)1e9) ? string("") : s.substr(start, minL);
    }
};

// optimal solution using a freq vector of integers
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        
        vector<int> freq(128, 0);
        for (char c : t) freq[c]++;
        
        int left = 0, right = 0;
        int count = t.size();
        int minLen = INT_MAX, start = 0;
        
        while (right < s.size()) {
            if (freq[s[right]] > 0) count--;
            freq[s[right]]--;
            right++;
            
            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                
                freq[s[left]]++;
                if (freq[s[left]] > 0) count++;
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
    
};