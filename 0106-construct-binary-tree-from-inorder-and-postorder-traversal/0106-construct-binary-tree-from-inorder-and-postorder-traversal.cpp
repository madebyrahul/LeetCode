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

    void createMapping(vector<int>& inorder,map<int,int> &nodeToIndex,int size){
        for(int i=0;i<size;i++){
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int postIdx,int inStart,int inEnd,map<int,int> &nodeToIndex){
        if(inStart>inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postIdx]);
        int position = nodeToIndex[postorder[postIdx]];
        root->right = solve(inorder,postorder,postIdx-1,position+1,inEnd,nodeToIndex);
        root->left = solve(inorder,postorder,postIdx - (inEnd-position) -1,inStart,position-1,nodeToIndex);
        return root;
    }
    

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size()-1;
        int inStart = 0,inEnd = inorder.size()-1;
        map<int,int> nodeToIndex;
        createMapping(inorder,nodeToIndex,inorder.size());
        TreeNode* ans  = solve(inorder,postorder,postIdx,inStart,inEnd,nodeToIndex);
        return ans;
    }
};