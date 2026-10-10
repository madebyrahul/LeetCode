class Solution {

    int solve(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index] + dp[index+1][0];
                    int ignore = 0 + dp[index+1][1];
                    profit = max(buyKaro,ignore);
                }else{ // sell
                    int sellKaro = +prices[index] + dp[index+1][1];
                    int ignore = 0 + dp[index+1][0];
                    profit = max(sellKaro,ignore);
                }

                dp[index][buy] =  profit;
            }
        }
        
        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};