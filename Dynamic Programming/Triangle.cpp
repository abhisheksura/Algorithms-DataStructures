/*
    LeetCode #120 - Triangle
    https://leetcode.com/problems/climbing-stairs/
    
    Time Complexity - O(MxN) / O(rows x cols)
    Space Complexity - O(1)
    Dynamic Programming - Bottom Up Approach
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // for each column in triangle
        for(int i=1; i < triangle.size(); i++) {
            // for each column in triangle
            for(int j=0; j < triangle[i].size(); j++) {
                
                // sum 1st element of current row with 1st element of previous row
                if (j == 0) {
                    triangle[i][j] = triangle[i-1][j] + triangle[i][j];
                }
                
                // sum the last element of current row with last element of previous row as it is a triangle we are doing j-1 of previous row
                else if(j == triangle[i].size()-1) {
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
                }
                
                // sum the current element with adjacent elements from previous row
                else {
                    triangle[i][j] = min(triangle[i-1][j], triangle[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        return *min_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
    }
};
