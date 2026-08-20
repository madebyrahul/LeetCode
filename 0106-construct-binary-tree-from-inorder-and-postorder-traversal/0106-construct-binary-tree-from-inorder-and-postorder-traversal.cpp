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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int postIdx,int inStart,int inEnd){
        if(inStart>inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postIdx]);
        int position = find(inorder,inStart,inEnd,postorder[postIdx]);
        root->right = solve(inorder,postorder,postIdx-1,position+1,inEnd);
        root->left = solve(inorder,postorder,postIdx - (inEnd-position) -1,inStart,position-1);
        return root;
    }
    

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size()-1;
        int inStart = 0,inEnd = inorder.size()-1;
        TreeNode* ans  = solve(inorder,postorder,postIdx,inStart,inEnd);
        return ans;
    }
};