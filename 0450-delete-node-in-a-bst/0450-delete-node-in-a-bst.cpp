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

    TreeNode* getMin(TreeNode* root){
        TreeNode* temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root == NULL){
            return root;
         }
         if(root->val == key){

            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->left != NULL && root->right != NULL){
                int minVal = getMin(root->right) -> val;
                root->val = minVal;
                root->right = deleteNode(root->right,minVal);
                return root;
            }

         }else if(root->val > key){
            root->left = deleteNode(root->left,key);
         }else{
            root->right = deleteNode(root->right,key);
         }
         return root;
    }
};