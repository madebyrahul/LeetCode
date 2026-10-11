class Solution {

    int solve(int k, vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2*k + 1,0);
        vector<int> next(2*k + 1,0);

        for(int index=n-1;index>=0;index--){
            for(int operationNum=0;operationNum<2*k;operationNum++){
                int profit = 0;
                if(operationNum % 2 == 0){
                    // even operation num is associated with buying allowed
                    int buyKaro = -prices[index] + next[operationNum + 1];
                    int skip = 0 + next[operationNum];
                    profit = max(buyKaro,skip);
                }else{
                    int sellKaro = +prices[index] + next[operationNum + 1];
                    int skip = 0 + next[operationNum];
                    profit = max(sellKaro,skip);
                }
                
                curr[operationNum] = profit;
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(k,prices);
    }
};