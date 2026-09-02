class Solution {

    void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<char>>& grid,int row,int col){
        if(i<0 || j<0 || j>=col || i>=row || vis[i][j] || grid[i][j] != '1'){
            return ;
        }
         vis[i][j] = true;
         dfs(i-1,j,vis,grid,row,col);
         dfs(i,j+1,vis,grid,row,col);
         dfs(i+1,j,vis,grid,row,col);
         dfs(i,j-1,vis,grid,row,col);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i,j,visited,grid,row,col);
                    islandCount++;
                }
            }
        }

        return islandCount;

    }
};