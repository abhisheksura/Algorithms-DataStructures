/*
    LeetCode #931 - Minimum Falling Path Sum
    https://leetcode.com/problems/minimum-falling-path-sum/
    
    Time Complexity - O(NxN)
    Space Complexity - O(NxN)
    Dynamic Programming - Bottom Up Approach
    
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        
        int dp[row][col];
        
        for (int i = 0; i < row; i++) {
            for (int j =0; j < col; j++ ) {
                /* Update the data for 1st row */
                if (i == 0) {
                    dp[i][j] = A[i][j];
                }
                /* Update the data for 1st column */
                else if (j == 0) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + A[i][j];
                }
                /* Update the data for last column */
                else if (j == col-1) {
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + A[i][j];
                }
                /* Update the data for middle rows and columns */
                else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]) + A[i][j];
                }
            }
        }
        
        /* Min path will be in the last row */
        int min_path = dp[row-1][0];
        
        for (int j = 1; j < col; j++)
        {
            min_path = min(min_path, dp[row-1][j]);
        }
        return min_path;
    }
};
