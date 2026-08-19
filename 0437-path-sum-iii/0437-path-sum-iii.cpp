/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    void solve(TreeNode* root, vector<int>& path, int& count, int k) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        solve(root->left, path, count, k);
        solve(root->right, path, count, k);
        int size = path.size();
        long long int sum = 0;
        for (int i = size - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k)
                count++;
        }
        path.pop_back();
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count = 0;
        solve(root, path, count, targetSum);
        return count;
    }
};