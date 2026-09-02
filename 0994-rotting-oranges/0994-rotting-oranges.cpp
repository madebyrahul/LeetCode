class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        
        queue<pair<pair<int,int>,int>> q; // { {i,j}, time}
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        int ans = 0;
       
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(time,ans);
            
            if(i-1>=0 && grid[i-1][j] == 1 && !visited[i-1][j]){
                q.push({{i-1,j},time+1});
                visited[i-1][j] = true;
            }

            if(j+1<col && grid[i][j+1] == 1 && !visited[i][j+1]){
                q.push({{i,j+1},time+1});
                visited[i][j+1] = true;
            }

            if(i+1<row && grid[i+1][j] == 1 && !visited[i+1][j]){
                q.push({{i+1,j},time+1});
                visited[i+1][j] = true;
            }

            if(j-1>=0 && grid[i][j-1] == 1 && !visited[i][j-1]){
                q.push({{i,j-1},time+1});
                visited[i][j-1] = true;
            }

        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }

        return ans;

    }
};