// Author : Shubham Chaudhari
// Date : 15/01/2024
// Problem : 2225. Find Players With Zero or One Losses
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15
// Video Solution : https://youtu.be/xIeU_x9gnss?si=JfSyEr9u5D2-_2_U
// Code:
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        set<int> allValues;
        vector<vector<int>> final(2);
        unordered_map<int, int> lost;
        int n = matches.size();

        for(auto match: matches){
            allValues.insert(match[0]);
            allValues.insert(match[1]);
            lost[match[1]]++;
        }

        for(auto element: allValues){
            if(lost[element] == 0){
                final[0].push_back(element);
            }
            if(lost[element] == 1){
                final[1].push_back(element);
            }
        }
        return final;
    }
};
