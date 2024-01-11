// Author : Shubham Chaudhari
// Date : 10/01/2024
// Problem : 1026. Maximum Difference Between Node and Ancestor
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11
// Video Solution : https://www.youtube.com/watch?v=4_OpFFPJwho

// Code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        int minValue = root->val, maxValue = root->val;

        differ(root, minValue, maxValue);
        return diff;
    }
private:
    int diff = 0;
    void differ(TreeNode* root, int minValue, int maxValue){
        if(!root){
            return;
        }

        diff = max(diff, max(abs(root->val - minValue), abs(root->val - maxValue)));

        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);

        differ(root->left, minValue, maxValue);
        differ(root->right, minValue, maxValue);
    }
};
