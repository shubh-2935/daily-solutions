// Author : Shubham Chaudhari
// Date : 27/01/2024
// Problem : 629. K Inverse Pairs Array
// Difficulty : Hard
// Problem Link : https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27
// Video Solution : https://www.youtube.com/watch?v=VrteHOB9004
// Code:
class Solution {
public:
    const int MOD = 1000000000 + 7;
    int kInversePairs(int n, int k) {
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i<=n; i++){
            for(int j=0; j<=k; j++){
                for(int x=0; x <= min(j, i-1); x++){

                    if(j - x >= 0){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;
                    }
                }
            }
        }

        return dp[n][k];
    }
};
