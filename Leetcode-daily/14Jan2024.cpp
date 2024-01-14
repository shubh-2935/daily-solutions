// Author : Shubham Chaudhari
// Date : 14/01/2024
// Problem : 1657. Determine if Two Strings Are Close
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14
// Video Solution : https://www.youtube.com/watch?v=dA6ByFNX958

// Code:
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for(char x: word1){
            count1[x - 'a']++;
        }
        for(char x: word2){
            count2[x - 'a']++;
        }

        for(int i=0; i<26; i++){
            if((count1[i] && !count2[i]) || (!count1[i] && count2[i])){
                return false;
            }
        }

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        for(int i=0; i<26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }

        return true;

    }
};
