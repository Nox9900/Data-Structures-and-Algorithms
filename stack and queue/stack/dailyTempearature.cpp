/*
    DAILY TEMPERATURES
    https://leetcode.com/problems/daily-temperatures/description/

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> dailyTemparatures(vector<int>& temperatures) {
            int n = temperatures.size();
            vector<int> result(n, 0);

            for(int i=n-2; i>=0; i--) {
                int j = i+1;
                while(temperatures[j] <= temperatures[i]) {
                    if(result[j] == 0) {
                        j = -1;
                        break;
                    }
                    j += result[j];
                }
                if(j != 1) result[i] = j-1;
            }
            return result;
        }
};