class Solution {

    int solve(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index] + dp[index+1][0][limit];
                        int skip = 0 + dp[index+1][1][limit];
                        profit = max(buyKaro,skip);
                    }else{
                        int sellKaro = +prices[index] + dp[index+1][1][limit-1];
                        int skip = 0 + dp[index+1][0][limit];
                        profit = max(sellKaro,skip);
                    }

                    dp[index][buy][limit] = profit;
                }
            }
        }
       
        return dp[0][1][2]; 
    }

public:
    int maxProfit(vector<int>& prices) {
        return solve(prices);
        
    }
};