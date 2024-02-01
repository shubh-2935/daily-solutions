// Author : Shubham Chaudhari
// Date : 01/02/2024
// Problem : 2966. Divide Array Into Arrays With Max Difference
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
// Video Solution : https://youtu.be/HrlEQgVNvgw
// Code:
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> final;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i=i+3){
            if(abs(nums[i] - nums[i+3-1]) <= k){
                final.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            else{
                return {};
            }
        }
        return final;
    }
};
