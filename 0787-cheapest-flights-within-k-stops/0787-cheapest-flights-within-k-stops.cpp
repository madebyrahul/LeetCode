class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adjList[u].push_back({v, wt});
        }

        vector<int> cost(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, -1}});

        while (!q.empty()) {
            auto val = q.front();
            q.pop();
            int node = val.first;
            int currCost = val.second.first;
            int stops = val.second.second;

            for (auto edge : adjList[node]) {
                int v = edge.first;
                int wt = edge.second;
                if (cost[v] > currCost + wt && stops + 1 <= k) {
                    cost[v] = currCost + wt;
                    q.push({v, {cost[v], stops + 1}});
                }
            }
        }

        if (cost[dst] == INT_MAX) return -1;
        return cost[dst];
    }
};