class Solution {

    int solve(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index] + next[0];
                    int ignore = 0 + next[1];
                    profit = max(buyKaro,ignore);
                }else{ // sell
                    int sellKaro = +prices[index] + next[1];
                    int ignore = 0 + next[0];
                    profit = max(sellKaro,ignore);
                }

                curr[buy] =  profit;
            }
            next = curr;
        }
        
        return next[1];
    }

public:
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};