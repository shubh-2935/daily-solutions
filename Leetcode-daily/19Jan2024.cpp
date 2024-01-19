// Author : Shubham Chaudhari
// Date : 19/01/2024
// Problem : 931. Minimum Falling Path Sum
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19
// Video Solution : https://youtu.be/qUJModr5Dqs
// Code:

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == 0){
                    dp[i][j] = matrix[i][j];
                }
                else if( j == 0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                }
                else if(j == n-1){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = matrix[i][j] + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]);
                }
            }
        }

        int result = INT_MAX;
        for(int j=0; j<n; j++){
            result = min(result, dp[n-1][j]);
        }
        return result;
    }
};
