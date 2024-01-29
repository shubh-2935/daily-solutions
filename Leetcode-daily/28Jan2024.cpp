// Author : Shubham Chaudhari
// Date : 28/01/2024
// Problem : 1074. Number of Submatrices That Sum to Target
// Difficulty : Hard
// Problem Link : https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/?envType=daily-question&envId=2024-01-28
// Video Solution : https://www.youtube.com/watch?v=TrSeCuhmAd0
// Code:
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        int count=0;

        for(int c1=0; c1<n; c1++){
            for(int c2=c1; c2<n; c2++){

                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;

                for(int row = 0; row<m ; row++){

                    sum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1-1] : 0);
                    count += mp[sum - target];
                    mp[sum]++;
                }

            }
        }

        return count;
    }
};
