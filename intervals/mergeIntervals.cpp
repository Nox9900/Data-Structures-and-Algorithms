/*
    MERGE INTERVALS
    https://leetcode.com/problems/merge-intervals
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
        });

        vector<vector<int>> merged;
        for(const auto& interval : intervals) {
            if(merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

// optimal solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        vector<vector<int>> res;

        for(int i = 1; i < n; i++) {

            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        res.push_back({start1, end1});
        return res;
    }
};