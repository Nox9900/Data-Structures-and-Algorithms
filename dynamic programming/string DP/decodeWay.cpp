#include<vector>
/*
    DECODE WAYS
    https://leetcode.com/problems/decode-ways/
*/


class Solution {
    public:
        int numDecoding(string s) {
            int n = s.size();
            vector<int> dp(n+1 , 0);
            dp[n] = 1;
            for(int i = n-1 ;i>=0; i--){
                if(s[i] != '0')dp[i] = dp[i+1];
                if(i + 1 < n){
                    int vv = stoi(s.substr(i , 2));
                    if(vv >= 10 && vv <= 26)dp[i] += dp[i + 2];
                }
            }
            return dp[0];
        }
};