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
            pair<int,int> p = {0,0};
            return p;
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        int d1 = left.first;
        int d2 = right.first;
        int d3 = left.second + right.second;
        pair<int,int> ans;
        ans.first = max(max(d1,d2),d3);
        ans.second = max(left.second,right.second) +1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};