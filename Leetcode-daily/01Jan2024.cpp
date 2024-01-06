// Author : Shubham Chaudhari
// Date : 01/01/2024
// Problem : Assign Cookies
// Difficulty : Easy
// Problem Link : https://leetcode.com/problems/assign-cookies/description/
// Video Solution : https://youtu.be/cfOzUdcQo3I
// Code:

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int greedSize = g.size();
        int cookieSize = s.size();

        if(cookieSize == 0){
            return 0;
        }

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0;
        int cookieIndex = cookieSize -1;
        int greedIndex = greedSize - 1;

        while(cookieIndex >= 0 && greedIndex >=0){

            if(s[cookieIndex] >= g[greedIndex]){
                maxNum++;
                cookieIndex--;
                greedIndex--;
            }
            else{
                greedIndex--;
            }

        }
        return maxNum;
    }
};