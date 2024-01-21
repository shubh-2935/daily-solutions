// Author : Shubham Chaudhari
// Date : 21/01/2024
// Problem : 198. House Robber
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21
// Video Solution : https://www.youtube.com/watch?v=CUSc2vv83WE
// Code:

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];
        
        int dp[n + 1];
        
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n; i++){
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }       

        return dp[n];
    }
};
