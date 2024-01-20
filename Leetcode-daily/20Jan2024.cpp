// Author : Shubham Chaudhari
// Date : 20/01/2024
// Problem : 907. Sum of Subarray Minimums
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20
// Video Solution : 
// Code:
class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n, -1);
        vector<int>right(n, n);

        stack<int> stk;
        
        for(int i=0; i<n; i++){
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                right[i] = stk.top();
            }
            stk.push(i);
        }

        long long sum = 0;

        for(int i=0; i<n; i++){
            sum += static_cast<long long>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            sum %= MOD;
        }

        return sum;

    }
};
