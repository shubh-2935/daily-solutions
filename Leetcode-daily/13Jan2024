// Author : Shubham Chaudhari
// Date : 13/01/2024
// Problem : 1347. Minimum Number of Steps to Make Two Strings Anagram
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13
// Video Solution : https://youtu.be/g0d22mvPwE8?si=ifYfkQ0P4O25lllW

// Code:
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        int i;
        for(i=0; i<n; i++){
            map1[s[i]]++;
            map2[t[i]]++;
        }
        int count = 0;
        for(auto x: map1){
            int sCount = x.second;
            int tCount = map2[x.first];
            int diff = sCount - tCount;
            if(diff > 0){
                count += diff;
            }
        }
        return count;
    }
};
