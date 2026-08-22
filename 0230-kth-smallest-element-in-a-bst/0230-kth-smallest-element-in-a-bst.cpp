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

    int solve(TreeNode* root,int k ,int &i){
        if(root == NULL){
            return -1;
        }
        int left = solve(root->left,k,i);
        if(left != -1){
            return left;
        }
        i++;
        if(i==k){
            return root->val;
        }
        int right = solve(root->right,k,i);
        if(right != -1){
            return right;
        }
        return -1;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = solve(root,k,i);
        return ans;
    }
};