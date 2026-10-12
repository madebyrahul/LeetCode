class Solution {

    int solve(string &a, string &b){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + dp[i+1][j+1];
                }else{
                    ans = max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] =  ans;
            }
        }

        return dp[0][0];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2);
    }
};