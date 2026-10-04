class Solution {

    int solve(int index,int endIdx,vector<int>& slices,int n,vector<vector<int>> &dp){
        if(n==0 || index>endIdx){
            return 0;
        }
        if(dp[index][n] != -1){
            return dp[index][n];
        }
        int take = slices[index] + solve(index+2,endIdx,slices,n-1,dp);
        int notTake = 0 + solve(index+1,endIdx,slices,n,dp);
        return dp[index][n] = max(take,notTake);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp(k,vector<int>(k,-1));
        int case1 = solve(0,k-2,slices,k/3,dp);
        dp.assign(k, vector<int>(k, -1));
        int case2 = solve(1,k-1,slices,k/3,dp);
        return max(case1,case2);
    }
};