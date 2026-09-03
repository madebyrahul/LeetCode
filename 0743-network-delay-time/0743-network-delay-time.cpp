class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adjList; 
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adjList[u].push_back({v,w});
        }

        vector<int> time(n+1);
        for(int i=1;i<=n;i++){
            time[i] = INT_MAX;
        }

        time[k] = 0;
        set<pair<int,int>> st; // here value is like {time,node} in this set.
        st.insert({0,k});

        while(!st.empty()){
            auto top = *(st.begin());
            int nodeTime = top.first;
            int node = top.second;
            st.erase(st.begin());
            for(auto neighbour : adjList[node]){
                if(nodeTime + neighbour.second < time[neighbour.first]){
                    auto record = st.find({time[neighbour.first],neighbour.first});
                    if(record != st.end()){
                        st.erase(record);
                    }
                    time[neighbour.first] = nodeTime + neighbour.second;
                    st.insert({time[neighbour.first],neighbour.first});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans,time[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};