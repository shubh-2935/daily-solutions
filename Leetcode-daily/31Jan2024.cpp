// Author : Shubham Chaudhari
// Date : 31/01/2024
// Problem : 739. Daily Temperatures
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/daily-temperatures/
// Video Solution : https://youtu.be/5Ueb8_tZCiI
// Code:

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int, int>> stk;
        vector<int> final;
        for(int i=temperatures.size()-1; i>=0; i--){

            while(!stk.empty() && temperatures[i] >= stk.top().first){
                stk.pop();
            }
            if(stk.empty()){
                final.push_back(0);
            }
            else{
                final.push_back(stk.top().second - i);
            }
            stk.push({temperatures[i], i});
        }

        int n = final.size();
        for(int i=0; i<n/2; i++){
            swap(final[i], final[n-1-i]);
        }
        return final;

    }
};
