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
        map<int,map<int,vector<int>>> mapping;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int horizontal = temp.second.first;
            int level = temp.second.second;
            mapping[horizontal][level].push_back(frontNode->val);
            if(frontNode->left){
                q.push({frontNode->left,{horizontal-1,level+1}});
            } 
            if(frontNode->right){
                q.push({frontNode->right,{horizontal+1,level+1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto i : mapping){
            vector<int> temp;
            for(auto j : i.second){
                sort(j.second.begin(),j.second.end());
                for( int k : j.second){
                     temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;

    }
};