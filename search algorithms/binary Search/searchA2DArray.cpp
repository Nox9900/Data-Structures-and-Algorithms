

/*
    SEARCH A 2D ARRAY
    https://leetcode.com/problems/search-a-2d-matrix/description/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n=matrix[0].size();
        int left =0, right = m*n;
        while(left < right) {
            int mid = left + (right-left) / 2;
            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) left = mid+1;
            else right = mid;
        }
        return false;
    }
};