// Author : Shubham Chaudhari
// Date : 07/02/2024
// Problem : 451. Sort Characters By Frequency
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
// Video Solution : 
// Code:

class Solution {
public:
    static bool comp(const pair<char, int>& a, const pair<char, int>& b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        map<char, int> mp;
        for(auto ch: s){
            mp[ch]++;
        }
        vector<pair<char, int>> vecs;
        for(auto m: mp){
            vecs.push_back({m.first, m.second});
        }
        sort(vecs.begin(), vecs.end(), comp);
        string str = "";
        for(auto vec: vecs){
            while(vec.second){
                str += vec.first;
                vec.second--;
            }
        }

        return str;
    }
};
