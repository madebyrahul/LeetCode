class Solution {

    int solve(string &a,string &b){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<m;j++){
            dp[n][j] = m-j;
        }

        for(int i=0;i<n;i++){
            dp[i][m] = n-i;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }else{
                    int insertAns = 1 + dp[i][j+1];
                    int deleteAns = 1 + dp[i+1][j];
                    int replaceAns = 1 + dp[i+1][j+1];
                    ans = min(insertAns , min(deleteAns , replaceAns));
                }
                dp[i][j] =  ans;
            }
        }

        return dp[0][0];
    }

public:
    int minDistance(string word1, string word2) {
        return solve(word1,word2);
    }
};