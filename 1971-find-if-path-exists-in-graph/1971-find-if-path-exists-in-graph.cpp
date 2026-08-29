class Solution {

    bool dfs(int source,int destination,vector<int> &visited,vector<vector<int>> &adjList){
         if(source == destination){
            return true;
         }
         visited[source] = true;
         for(int i : adjList[source]){
            if(!visited[i]){
                if(dfs(i,destination,visited,adjList)){
                    return true;
                }
            }
         }
         return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);              //sized with n
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> visited(n,false);
        return dfs(source,destination,visited,adjList);
    }
};