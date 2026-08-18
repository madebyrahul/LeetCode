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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodesMap;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* curr = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            nodesMap[col][row].push_back(curr->val);

            if (curr->left != NULL)
                q.push({curr->left, {row + 1, col - 1}});

            if (curr->right != NULL)
                q.push({curr->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;

        for (auto col : nodesMap) {
            vector<int> temp;

            for (auto row : col.second) {
                sort(row.second.begin(), row.second.end());

                for (int value : row.second)
                    temp.push_back(value);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};