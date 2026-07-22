#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObtstacles(vector<vector<int>>& obstaclesGrid) {
        if(obstaclesGrid[0][0] == 1) return 0;
        int m = obstaclesGrid.size(), n = obstaclesGrid[0].size();
        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<0; j++) {
                if(obstaclesGrid[i][j] == 1) dp[j] = 0;
                else if(j>0) dp[j] += dp[j+1]; 
            }
        }
        return dp[n-1];
    }
};