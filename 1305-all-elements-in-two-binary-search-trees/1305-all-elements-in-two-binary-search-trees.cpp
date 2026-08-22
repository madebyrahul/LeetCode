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

    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    vector<int> merge(vector<int> &a,vector<int> &b){
        vector<int> ans(a.size() + b.size());
        int i=0,j=0,k=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                ans[k++] = a[i++];
            }else{
                ans[k++] = b[j++];
            }
        }
        while(i<a.size()){
            ans[k++] = a[i++];
        }
        while(j<b.size()){
            ans[k++] = b[j++];
        }
        return ans;
    }


public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder1,inorder2;
        inorder(root1,inorder1);
        inorder(root2,inorder2);
        vector<int> mergeInorder = merge(inorder1,inorder2);
        return mergeInorder;
    }
};