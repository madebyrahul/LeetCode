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

    TreeNode* createMapping(TreeNode* root,map<TreeNode*,TreeNode*> &nodeToParent, int target){
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        TreeNode* res = NULL;
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            if(frontNode->val == target){
                res = frontNode;
            }
            if(frontNode->left){
                nodeToParent[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right){
                nodeToParent[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
        }
        return res;
    }

    int burnTree(TreeNode* root,map<TreeNode*,TreeNode*> &nodeToParent){
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            bool added = false;
            for(int i=0;i<size;i++){
                TreeNode* frontNode = q.front();
                q.pop();
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                   added = true;
                   q.push(nodeToParent[frontNode]);
                   visited[nodeToParent[frontNode]] = true;
                }
                if(frontNode->left && !visited[frontNode->left]){
                    added = true;
                    q.push(frontNode->left);
                    visited[frontNode->left] = true;
                }
                if(frontNode->right && !visited[frontNode->right]){
                    added = true;
                    q.push(frontNode->right);
                    visited[frontNode->right] = true;
                }
            }
            if(added) time++;
        }
        return time;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* targetNode = createMapping(root,nodeToParent,start);
        int time = burnTree(targetNode,nodeToParent);
        return time;
    }
};