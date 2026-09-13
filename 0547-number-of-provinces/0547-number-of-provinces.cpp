class Solution {

    void dfs(int i,vector<vector<int>>& adj,vector<int> &vis){
        vis[i] = true;
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j] == 1 && !vis[j]){
                dfs(j,adj,vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int num = 0;
        vector<int> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                num++;
            }
        }
        return num;
    }
};