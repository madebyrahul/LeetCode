class Solution {

    int findParent(int node,vector<int> &parent){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node],parent);
    }

    void unionSet(int u,int v,vector<int>& parent,vector<int> &rank){
        u = findParent(u,parent);
        v = findParent(v,parent);
        if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[u] > rank[v]){
            parent[v] = u;
        }else{
            parent[u] = v;
            rank[v]++;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1){
            return -1;
        }

        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        int component = n;
        for(auto vect : connections){
            int u = findParent(vect[0], parent);
            int v = findParent(vect[1], parent);
            if( u != v){
                unionSet(u,v,parent,rank);
                component--;
            }
        }

        return component-1;

    }
};