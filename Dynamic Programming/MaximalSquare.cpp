"""
    LeetCode #221 - Maximal Square
    https://leetcode.com/problems/maximal-square/
    
    Time Complexity - O(NxN)
    Space Complexity - O(NxN)
    Dynamic Programming - Bottom Up Approach
"""

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        
        int max_square = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int dp[row+1][col+1];

        for (int i=0; i<=row; i++) {
            for (int j=0; j<=col; j++) {
                if ( i == 0 || j == 0) {
                    // initialize the top row and first column as 0's
                    dp[i][j] = 0;
                }
                else {
                    if (matrix[i-1][j-1] == '1') {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                        max_square = max(max_square, dp[i][j]);
                    }
                    else if (matrix[i-1][j-1] == '0'){
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return max_square * max_square;
    }
};
