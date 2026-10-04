class Solution {

    #define MOD 1000000007

    int solve(int d,int f,int t){
        vector<vector<long long>> dp(d+1,vector<long long>(t+1,0));
        dp[0][0] = 1;

        for(int dice=1;dice<=d;dice++){
            for(int target=1;target<=t;target++){
                    long long ans = 0;
                    for(int i=1;i<=f;i++){
                        if(target-i >= 0)                              
                            ans = (ans + dp[dice-1][target-i]) % MOD;

                    }
                    dp[dice][target] =  ans%MOD;
            }
        }

        return dp[d][t];

    }

public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }
};