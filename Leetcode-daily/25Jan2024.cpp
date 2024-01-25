// Author : Shubham Chaudhari
// Date : 25/01/2024
// Problem : 1143. Longest Common Subsequence
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25
// Video Solution : https://www.youtube.com/watch?v=euzlA--uoDc
// Code:
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length(), m = text2.length();

        int dp[n+1][m+1];

        for(int i=0; i<=m; i++){
            dp[0][i] = 0;
        }
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];

    }
};
