// Author : Shubham Chaudhari
// Date : 10/01/2024
// Problem : 1026. Maximum Difference Between Node and Ancestor
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11
// Video Solution : https://www.youtube.com/watch?v=4_OpFFPJwho

// Code:
class Solution {
public:
    bool halvesAreAlike(string s) {
       unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int count = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(vowels.count(s[i]) && i<n/2){
                count++;
            }
            else if(vowels.count(s[i]) && i>=n/2){
                count--;
            }
        }
        return (count == 0);
    }   
};
