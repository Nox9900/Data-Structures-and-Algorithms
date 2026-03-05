#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int& c:nums) {
            freq[c]++;
        }
        vector<int>res;
        for(const auto& c:freq){
            if(c.second==1) res.push_back(c.first);
        }
        return res;
    }

};