/*
    NUMBER OF ISLANDS
    https://leetcode.com/problems/number-of-islands

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       if(grid.empty() || grid[0].empty()) return 0;

       int numIslands =0, rows=grid.size(), cols = grid[0].size();
       vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

       for(int r=0; r<rows; r++) {
        for(int c=0; c<cols; c++) {
            if(grid[r][c] == '1') {
                numIslands++;
                queue<pair<int, int>>qt;
                qt.push({r,c});
                grid[r][c] = '0';

                while(!qt.empty()) {
                    auto curr = qt.front();
                    qt.pop();

                    for(const auto& dir : directions) {
                        int newRow = curr.first + dir.first;
                        int newCol = curr.second + dir.second;

                        if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == '1') {
                            qt.push({newRow, newCol});
                            grid[newRow][newCol] = '0';
                        }
                    }
                }
            }
        }
       } 
       return numIslands;
    }
};


class Solution {
public:
void dfs(vector<vector<char>>& grid,int r,int c,int &n,int &m){
    if( grid[r][c]=='0'){
        return;
    }
    grid[r][c]='0';

    if(r-1>=0 && grid[r-1][c]=='1'){
        dfs(grid,r-1,c,n,m);
    }
    if(c+1<m && grid[r][c+1]=='1'){
        dfs(grid,r,c+1,n,m);
    }
    if(r+1<n && grid[r+1][c]=='1'){
        dfs(grid,r+1,c,n,m);
    }
    if(c-1>=0 && grid[r][c-1]=='1'){
        dfs(grid,r,c-1,n,m);
    }

}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    cnt++;
                }
            }

        }
        return cnt;
        
    }
};