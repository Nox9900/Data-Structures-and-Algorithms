#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(string& c:strs) {
            string newStr = c;
            sort(newStr.begin(), newStr.end());
            res[newStr].push_back(c);
        }
        vector<vector<string>> ans;
        for(auto& c:res){
            ans.push_back(c.second);
        }
        return ans;
    }
};