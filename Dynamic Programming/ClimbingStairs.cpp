/*
    LeetCode #70 - Climbing Stairs
    https://leetcode.com/problems/climbing-stairs/
    
    Time Complexity - O(N)
    Space Complexity - O(N)
    Dynamic Programming - Bottom Up Approach
    
    This is same as Fibonacci Series and can have Space Complexity - O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
