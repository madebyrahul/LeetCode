class Solution {

    typedef pair<int,int> P;

    int primsAlgo(vector<vector<P>> &adjList,int &vert){
        vector<bool> visited(vert,false);
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int w = top.first;
            int node = top.second;
            if(visited[node]) continue;
            sum += w;
            visited[node] = true;
            for(auto neighbour : adjList[node]){
                int next = neighbour.first;
                int weight = neighbour.second;
                if(!visited[next]){
                    pq.push({weight,next});
                }
            }
        }
        return sum;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int vertices = points.size();
        vector<vector<P>> adjList(vertices); // {v,w} at index of u
        for(int i=0;i<vertices;i++){
            for(int j=i+1;j<vertices;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int dist = abs(x1-x2) + abs(y1-y2);
                adjList[i].push_back({j,dist});
                adjList[j].push_back({i,dist});
            }
        }
        
        return primsAlgo(adjList,vertices);
        
    }
};