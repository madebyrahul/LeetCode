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

    TreeNode* buildTree(vector<int>& nums,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums,s,mid-1);
        root->right = buildTree(nums,mid+1,e);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int st =0,end = nums.size()-1;
        return buildTree(nums,st,end);
    }
};