// Author : Shubham Chaudhari
// Date : 05/01/2024
// Problem : Longest Increasing Subsequence
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/description/
// Video Solution : https://youtu.be/ekS9ZLt9d24?si=J2PafzhBulF-XVlH
// Code:

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int tail[n];
        tail[0] = nums[0];
        int size = 1;
        if(n == 0){
            return 0;
        }
        for(int i=1; i<n; i++){
            if(tail[size-1] <nums[i]){
                tail[size] = nums[i];
                size++;
            }
            else{
                int index = midIndex(tail, 0, size-1, nums[i]);
                tail[index] = nums[i];
            }
        }
        return size;
    }
private:
    int midIndex(const int nums[], int start, int end, int num){
        while(start<end){
            int mid = start + ((end - start) / 2);
            if(nums[mid] >= num){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return end;
    }
};