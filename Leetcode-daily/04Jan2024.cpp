// Author : Shubham Chaudhari
// Date : 04/01/2024
// Problem : minimum-number-of-operations-to-make-array-empty
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/
// Video Solution : https://youtu.be/7jbZJ2NTcgI
// Code:

class Solution {
public:
    int minOperations(vector<int>& nums){
        
        int count = 0;
        unordered_map<int, int> arr;
        for(int i=0; i<nums.size(); i++){
            arr[nums[i]]++;
        }
        for(auto i: arr){
            int num = i.second;
            if(num == 1){
                return -1;
            }
            else{
                int newCount = (i.second/3);
                count += ((i.second % 3 == 0) ? newCount : newCount + 1);
            }
        }
        return count;
    }
};