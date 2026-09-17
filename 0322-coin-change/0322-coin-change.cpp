class Solution {

    int solve(vector<int>& coins,vector<int> &dp, int amount){
        if(amount == 0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins,dp,amount-coins[i]);
            if(ans != INT_MAX){
                mini = min(ans+1,mini);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans =  solve(coins,dp,amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};