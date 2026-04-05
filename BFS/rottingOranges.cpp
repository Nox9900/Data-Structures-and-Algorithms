#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> qt;
        int freshCnt = 0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    qt.push({i, j});
                } else if(grid[i][j] == 1) {
                    freshCnt++;
                }
            }
        }

        int min = 0;
        while(!qt.empty() && freshCnt > 0) {
            min++;
            int size = qt.size();

            for(int i=0; i<size; i++) {
                auto pt = qt.front();
                qt.pop();

                for(int d=0; d<4; d++) {
                    int newRow = pt.first + dx[d];
                    int newCol = pt.second + dy[d];

                    if(newRow >=0 && newRow < rows && newCol >= 0 && newCol < cols
                        && grid[newRow][newCol] == 1
                    ) {
                        grid[newRow][newCol] = 2;
                        qt.push({newRow, newCol});
                        freshCnt--;
                    }
                }
            }
        }

        return freshCnt == 0 ? min : -1;
    }
};