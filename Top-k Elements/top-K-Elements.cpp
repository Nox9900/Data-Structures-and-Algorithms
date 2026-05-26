/*
    TOP K-FREQUENT ELEMENT
    https://leetcode.com/problems/top-k-frequent-elements
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int& num:nums) cnt[num]++;

        vector<vector<int>> bucket(nums.size()+1);
        for(const auto& entry:cnt) {
            int num = entry.first;
            int freq = entry.second;
            bucket[freq].push_back(num);
        }

        vector<int> top;
        for(int i=bucket.size()-1; i >=0 && top.size()<k; i--) {
            if(!bucket[i].empty()){
                for(int& num : bucket[i]) {
                    top.push_back(num);
                    if(top.size() == k) return top;
                }
            }
        }
        return top;
    }
};