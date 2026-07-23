/*
    TOP K FREQUENT WORDS
    https://leetcode.com/problems/top-k-frequent-words
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> topKelement(vector<string>& words, int k) {
            unordered_map<string, int> ans;
            for(string& word : words) {
                ans[word]++;
            }

            vector<pair<string, int>> q(ans.begin(), ans.end());
            sort(q.begin(), q.end(), [](auto& a, auto& b) {  //lambda function
                if(a.second == b.second) return a.first < b.first;
                return a.second > b.second;
            });
            
            vector<string> result;
            for(int i=0; i<k; i++) {
                result.push_back(q[i].first);
            }

            return result;
        } 
};