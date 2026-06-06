/*
    SET MATRIX ZEROES
    https://leetcode.com/problems/set-matrix-zeroes/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size(), n = matrix[0].size();
            bool firstCol = false;

            for(int i=0; i<m; i++) {
                if(matrix[i][0] == 0) firstCol = true;
                for(int j=1; j<n; j++) {
                    if(matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
};