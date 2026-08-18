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

    void solve(TreeNode* root, vector<int> &ans,int lvl){
        if(root == NULL) return;
        if(lvl == ans.size()){
            ans.push_back(root->val);
        }
        solve(root->left,ans,lvl+1);
        solve(root->right,ans,lvl+1);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        int size = ans.size();
        return ans[size-1];
    }
};