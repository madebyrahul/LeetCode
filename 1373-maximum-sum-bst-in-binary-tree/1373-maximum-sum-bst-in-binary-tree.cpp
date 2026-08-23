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
    class info {
        public:
         int maxi;
         int mini;
         int sum;
         bool isBST;
    };

    info solve(TreeNode* root,int &ans){
        if(root == NULL){
            return {INT_MIN,INT_MAX,0,true};
        }
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);
        info currNode;
        currNode.maxi = max(root->val,right.maxi);
        currNode.mini = min(root->val,left.mini);
        currNode.sum = left.sum + right.sum + root->val;
        if(left.isBST && right.isBST && (left.maxi < root->val && root->val < right.mini)){
            currNode.isBST = true;
        }else{
            currNode.isBST = false;
        }
        if(currNode.isBST){
            ans = max(ans,currNode.sum);
        }
        return currNode;
    }

public:
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        info temp = solve(root,sum);
        return sum;
    }
};