#include<vector>

/*
    MIN COST TO CONNECT ALL POINTS
    https://leetcode.com/problems/min-cost-to-connect-all-points/
*/



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n =points.size();
        vector<int> minDist(n);
        
        for(int i = 1; i<n; i++){
            minDist[i] = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
        }
        minDist[0] = -1;
        int total = 0;
        for(int i = 0; i<n-1; i++) {
            int u = -1;
            for(int j = 0; j<n; j++) {
                if(minDist[j] >= 0 && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }
            total += minDist[u];
            minDist[u] = -1;

            for(int d=0; d<n; d++) {
                if(minDist[d] >= 0) {
                    int dist = abs(points[u][0] - points[d][0]) + abs(points[u][1] - points[d][1]);
                    minDist[d] = min(minDist[d], dist); 
                }
            }
        }
        return total;
    }
};