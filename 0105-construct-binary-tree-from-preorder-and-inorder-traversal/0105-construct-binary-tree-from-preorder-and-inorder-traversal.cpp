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

    int find(vector<int>& inorder,int s,int e,int val){
        for(int i=s;i<=e;i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }
   
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int preIdx,int inStart,int inEnd){
        if(inStart>inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int position = find(inorder,inStart,inEnd,preorder[preIdx]);
        root->left = solve(preorder,inorder,preIdx+1,inStart,position-1);
        root->right = solve(preorder,inorder,preIdx + (position-inStart) + 1,position+1,inEnd);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        int inStart = 0,inEnd = inorder.size()-1;
        TreeNode* ans = solve(preorder,inorder,preIdx,inStart,inEnd);
        return ans;
    }
};