/*
    LeetCode #64 - Minimum Path Sum
    https://leetcode.com/problems/minimum-path-sum/
   
    Time Complexity O(NxM)
    Dynamic Programming - Bottom Up Approach
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int row = grid.size(); /* Row Size */
        int col = grid[0].size(); /* Col Size */
        
        /* [0][0] will be as it is and we will update from the next element */
        for (int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (i == 0 && j > 0) {
                    /* Update the top row */
                    grid[i][j] += grid[i][j-1];
                }
                else if (i > 0 && j == 0) {
                    /* Update the left column */
                    grid[i][j] += grid[i-1][j];
                }
                else if (i > 0 && j > 0) {
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
                }
            }
        }
        return grid[row-1][col-1];
    }
};
