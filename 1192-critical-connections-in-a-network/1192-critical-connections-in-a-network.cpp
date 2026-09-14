class Solution {

    void DFS(int node,int parent,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,vector<bool> &vis,vector<vector<int>> &bridges,int &count){
        disc[node] = low[node] = count;
        vis[node] = true;
        for(int i=0;i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(neigh == parent){
                continue;
            }else if(vis[neigh]){
                low[node] = min(low[node],low[neigh]);
            }else{
                count++;
                DFS(neigh,node,adj,disc,low,vis,bridges,count);
                low[node] = min(low[node],low[neigh]);
                if(low[neigh] > disc[node]){
                    vector<int> temp;
                    temp.push_back(neigh);
                    temp.push_back(node);
                    bridges.push_back(temp);
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> bridges;
        vector<int> discovery(n);
        vector<int> low(n);
        vector<bool> visited(n,false);

        int count = 0;
        DFS(0,-1,adjList,discovery,low,visited,bridges,count);

        return bridges;

    }
};