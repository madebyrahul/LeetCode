class Solution {

    int solve(int index,int operationNum,int k, vector<int>& prices,vector<vector<int>> &dp){
        if(index == prices.size()){
            return 0;
        }
        if(operationNum == 2*k){
            return 0;
        }

        if(dp[index][operationNum] != -1 ){
            return dp[index][operationNum] ;
        }

        int profit = 0;
        if(operationNum % 2 == 0){
            // even operation num is associated with buying allowed
            int buyKaro = -prices[index] + solve(index+1,operationNum + 1,k,prices,dp);
            int skip = 0 + solve(index+1,operationNum,k,prices,dp);
            profit = max(buyKaro,skip);
        }else{
            int sellKaro = +prices[index] + solve(index+1,operationNum + 1,k,prices,dp);
            int skip = 0 + solve(index+1,operationNum,k,prices,dp);
            profit = max(sellKaro,skip);
        }
        
        return dp[index][operationNum] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2*k,-1));
        return solve(0,0,k,prices,dp);
    }
};