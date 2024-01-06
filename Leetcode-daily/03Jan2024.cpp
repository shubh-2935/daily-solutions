// Author : Shubham Chaudhari
// Date : 03/01/2024
// Problem : number-of-laser-beams-in-a-bank
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/
// Video Solution : https://youtu.be/EVbfdN7TT_0
// Code:

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalCount = 0;
        int currCount  = 0;
        int prevCount = 0;

        for(string str: bank){

            currCount = count(str);
            if(currCount == 0){
                continue;
            }
            totalCount += (currCount * prevCount);
            prevCount = currCount;
        }
        return totalCount;
    }
private:
    int count(string str){
        int count = 0;
        for(int i=0; i<str.length(); i++){
            if(str[i] == '1'){
                count++;
            }
        }
        return count;
    }
};