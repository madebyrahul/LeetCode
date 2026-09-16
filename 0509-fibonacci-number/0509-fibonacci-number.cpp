class Solution {

    int solve(int n,vector<int> &dp){
        if(n<=1) return n;

        if(dp[n] != -1) return dp[n];
        dp[n] = solve(n-1,dp) + solve(n-2,dp);

        return dp[n];
    }

public:
    int fib(int n) {
        // solved by top-down approach of DP
        vector<int> dp(n+1);
        for(int i=0;i<n+1;i++){
            dp[i] = -1;
        }

        return solve(n,dp);
    }
};