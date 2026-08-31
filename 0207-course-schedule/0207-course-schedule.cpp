class Solution {

    bool isCycleDFS(int node,vector<bool> &visited,vector<bool> &recPath,vector<vector<int>> &edges){
        visited[node] = true;
        recPath[node] = true;
        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];
            if(u == node){
                if(!visited[v]){
                    if(isCycleDFS(v,visited,recPath,edges)){
                        return true;
                    }
                }else{
                    if(recPath[v]){
                        return true;
                    }
                }
            }
        }
        recPath[node] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> &edges = prerequisites;
        vector<bool> recPath(n,false);
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCycleDFS(i,visited,recPath,edges)){
                    return false;
                }
            }
        }

        return true;

    }
};