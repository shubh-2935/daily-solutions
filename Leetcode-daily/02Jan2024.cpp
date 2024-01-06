// Author : Shubham Chaudhari
// Date : 02/01/2024
// Problem : convert-an-array-into-a-2d-array-with-conditions
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/
// Video Solution : https://youtu.be/Y6QJww6HuXE
// Code:

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
       unordered_map<int, int> freqMap;

       for(int i: nums){
           freqMap[i]++;
       }

       vector<int> sortedNums = nums;
       sort(sortedNums.begin(), sortedNums.end(), [&](int a, int b){
           return freqMap[a] > freqMap[b];
       });

        vector<vector<int>> rows;

        for(int num : sortedNums){
            bool added = false;
            for(vector<int>&row : rows){
                if(find(row.begin(), row.end(), num) == row.end()){
                    row.push_back(num);
                    added = true;
                    break;
                }
            }
            if(!added){
                rows.push_back({num});
            }
        }
        return rows;

    }
};