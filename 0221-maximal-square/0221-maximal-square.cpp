class Solution {

    void solve(vector<vector<char>>& mat, int& maxi) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if (mat[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(dp[i][j], maxi);
                    
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        solve(matrix, maxi);
        return maxi * maxi;
    }
};