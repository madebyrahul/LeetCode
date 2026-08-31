class Solution {

    bool isCycleByDFS(int node,vector<bool> &vis,vector<bool> &recPath,vector<vector<int>> &edges){
        vis[node] = true;
        recPath[node] = true;
        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];
            if(u == node){
                if(!vis[v]){
                    if(isCycleByDFS(v,vis,recPath,edges)){
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

    void topoLogicalOrder(int node,vector<bool> &vis,stack<int> &s,vector<vector<int>> &edges){
        vis[node] = true;

        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];
            if(u == node){
                if(!vis[v]){
                    topoLogicalOrder(v,vis,s,edges);
                }
            }
        }

        s.push(node);

    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> &edges = prerequisites;
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycleByDFS(i,vis,recPath,edges)){
                    return ans;
                }
            }
        }

        stack<int> s;
        vis.assign(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoLogicalOrder(i,vis,s,edges);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;

    }
};