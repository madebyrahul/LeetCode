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

    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            pair<int,int> p ={0,0};
            return p;
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        pair<int,int> ans;
        ans.first = root->val + left.second + right.second;
        ans.second = max(left.first, left.second) + max(right.first, right.second);
        return ans;
    }

public:
    int rob(TreeNode* root) {
        pair<int,int> p = solve(root);
        return max(p.first,p.second);
    }
};