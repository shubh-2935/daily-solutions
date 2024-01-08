// Author : Shubham Chaudhari
// Date : 08/01/2024
// Problem : 938. Range Sum of BST
// Difficulty : Easy
// Problem Link : https://leetcode.com/problems/range-sum-of-bst/description/?envType=daily-question&envId=2024-01-08
// Video Solution : https://youtu.be/g9rWB4jgLgI?si=EP9TArRyLG8OLzQs

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root == nullptr){
            return 0;
        }
        int sum = 0;
        
        if(low <= root->val && root->val <= high){
            sum = root->val;
        }

        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);

        return sum;
    }
};
