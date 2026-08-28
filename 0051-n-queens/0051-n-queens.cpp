class Solution {

    bool isSafe(vector<string> &board,int row,int col,int n){
         for(int j=0;j<n;j++){
            if(board[row][j] == 'Q'){
                return false;
            }
         }

         for(int i=0;i<n;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
         }

         for(int i=row,j=col ; i>=0 && j>= 0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
         }

         for(int i=row,j=col ; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
         }

         return true;
    }

    void nQueens(vector<string> &board,vector<vector<string>> &ans,int row,int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j] = 'Q';
                nQueens(board,ans,row+1,n);
                board[row][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        int row = 0;
        nQueens(board,ans,row,n);
        return ans;
    }
};