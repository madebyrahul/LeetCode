class Solution {

    int solve(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    ans = min(ans,v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                    dp[i][j] = ans;
                }
            }
        }

        return dp[0][n-1];
    }

public:
    int minScoreTriangulation(vector<int>& values){
        return solve(values);
    }
};