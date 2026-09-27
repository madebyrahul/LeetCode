class Solution {

    int solve(int n,vector<int>& days, vector<int>& costs){
       vector<int> dp(n+1,-1);
       dp[n] = 0;

        for(int k=n-1;k>=0;k--){
           int option1 = costs[0] + dp[k+1];
           int i;
           for(i=k; i<n && days[i] < days[k] + 7;i++){}
           int option2 = costs[1] + dp[i];
           for(i=k; i<n && days[i] < days[k] + 30;i++){}
           int option3 = costs[2] + dp[i];
           dp[k] =  min(option1,min(option2,option3));
        }

        return dp[0];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(n,days,costs);
    }
};