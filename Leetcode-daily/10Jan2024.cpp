// Author : Shubham Chaudhari
// Date : 10/01/2024
// Problem : 2385. Amount of Time for Binary Tree to Be Infected
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
// Video Solution : https://youtu.be/px9Y9FRSBWs

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
    unordered_map<int, vector<int>> graph;
    int amountOfTime(TreeNode* root, int start) {
        int minute = -1;
        buildTree(root);

        unordered_set<int> visited;
        queue<int> que;
        que.push(start);
        while(!que.empty()){
            minute++;
            for(int size = que.size(); size>0; size--){
                int curr = que.front();
                que.pop();
                visited.insert(curr);

                for(int adjacent: graph[curr]){
                    if(!visited.count(adjacent)){
                        que.push(adjacent);
                    }
                }
            }
        }
        return minute;
    }
private:
    void buildTree(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        buildTree(root->left);
        buildTree(root->right);
    }
};
