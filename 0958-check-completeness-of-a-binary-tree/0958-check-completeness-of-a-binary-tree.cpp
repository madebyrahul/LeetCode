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

    int countNodes(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int ans = countNodes(root->left) + countNodes(root->right) + 1;
        return ans;
    }

    bool solve(TreeNode* root , int cnt,int i){
        if(root == NULL){
            return true;
        };
        if(i>cnt){
            return false;
        }
        else{
            int left = 2*i;
            int right = 2*i+1;
            return solve(root->left,cnt,left) && solve(root->right,cnt,right);
        }
    }

public:
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        int index = 1;
        return solve(root,totalNodes,index);
    }
};