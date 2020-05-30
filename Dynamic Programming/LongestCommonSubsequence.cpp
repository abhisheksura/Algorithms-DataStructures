"""
    LeetCode #1143 - Longest Common Subsequence
    https://leetcode.com/problems/longest-common-subsequence/
    
    Time Complexity - O(MxN)
    Space Complexity - O(MxN)
    Dynamic Programming - Bottom Up Approach
"""

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text1.length();
        int col = text2.length();
        int dp[row+1][col+1];
        
        for (int i=0; i<=row; i++) {
            for(int j=0; j<=col; j++) {
                
                /* Update the data for 1st row and 1st col as 0 */
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else {
                    // if the string matches then diagonal element + 1
                    if (text1[i-1] == text2[j-1]) {
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    // else max of adjacent element
                    else {
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }   
                }
            }
        }
        return dp[row][col];
    }
};
