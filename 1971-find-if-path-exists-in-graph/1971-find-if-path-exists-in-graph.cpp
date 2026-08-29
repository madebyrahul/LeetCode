class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> visited(n,false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int val: adjList[node]){
                if(!visited[val]){
                    visited[val] = true;
                    q.push(val);
                }
            }
        }
        return visited[destination] ? true : false;
    }
};