// Author : Shubham Chaudhari
// Date : 18/01/2024
// Problem : 70. Climbing Stairs
// Difficulty : Easy
// Problem Link : https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18
// Video Solution : https://youtu.be/psDO_8j96PM
// Code:

class Solution {
public:
    int climbStairs(int n) {

        int dp[n + 1];

        dp[0] =1, dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
 
        return dp[n];
    }
};
