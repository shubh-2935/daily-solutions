// Author : Shubham Chaudhari
// Date : 22/01/2024
// Problem : 645. Set Mismatch
// Difficulty : Easy
// Problem Link : https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
// Video Solution : https://youtu.be/YEMjFWo82hY
// Code:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        int actualSum = 0;
        int realSum = ((n * (n + 1)) / 2);

        unordered_set<int> st(nums.begin(), nums.end());

        for(int i=0 ; i<n; i++){
            actualSum += nums[i];
        }

        int uniqueSum = 0;
        for(int x: st){
            uniqueSum += x;
        }

        int dup = actualSum - uniqueSum;
        int ubsent = realSum - uniqueSum;

        return {dup, ubsent};
    }
};
