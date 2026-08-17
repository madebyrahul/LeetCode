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

    pair<bool,int> solve(TreeNode* root){
        if(root == NULL){
            pair<bool,int> p = {true,0};
            return p;
        }
        pair<bool,int> left = solve(root->left);
        pair<bool,int> right = solve(root->right);
        bool heightBalance = abs( left.second - right.second ) <= 1;
        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1;
        if(heightBalance && left.first && right.first){
             ans.first = true;
        }else{
            ans.first = false;
        }
        return ans;
    }

public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};