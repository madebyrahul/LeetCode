class Solution {

    #define MOD 1000000007

    int solve(int d,int f,int t){
        vector<long long> prev(t+1,0);
        vector<long long> curr(t+1,0);
        prev[0] = 1;

        for(int dice=1;dice<=d;dice++){
            for(int target=1;target<=t;target++){
                    long long ans = 0;
                    for(int i=1;i<=f;i++){
                        if(target-i >= 0)                              
                            ans = (ans + prev[target-i]) % MOD;

                    }
                    curr[target] =  ans%MOD;
            }
            prev = curr;
        }

        return prev[t];

    }

public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }
};