// Author : Shubham Chaudhari
// Date : 16/01/2024
// Problem : 1207. Unique Number of Occurrences
// Difficulty : Easy
// Problem Link : https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17
// Video Solution : 
// Code:

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        unordered_set<int> st;

        for(auto x: arr){
            mp[x]++;
        }

        for(auto y: mp){
            if(st.find(y.second) == st.end()){
                st.insert(y.second);
            }
            else{
                return false;
            }
        }
        return true;
    }
};
