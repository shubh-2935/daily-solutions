// Author : Shubham Chaudhari
// Date : 06/01/2024
// Problem : Array Pair Sum Divisibility Problem
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/?envType=daily-question&envId=2024-01-06
// Video Solution : https://youtu.be/ACHpwyOBCAU?si=x4YTJsPpB9zKby-p

// Code:

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<tuple<int, int, int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {endTime[i], startTime[i], profit[i]};
        }

        sort(arr.begin(), arr.end());
        vector<int> dp(n+1);

        for(int i=0; i<n; i++){
            auto [endTime, startTime, profit] = arr[i];

            int noConflictIndex = upper_bound(arr.begin(), arr.begin()+i, startTime, [&](int time, const auto& job) -> bool{
                return time < get<0>(job);
            }) - arr.begin();

            dp[i+1] = max(dp[noConflictIndex] + profit, dp[i]);

        }
        return dp[n];

    }
};