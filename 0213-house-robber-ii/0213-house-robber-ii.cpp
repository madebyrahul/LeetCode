class Solution {

    int solve(int index,vector<int> &v,vector<int> &dp){
        int n = v.size();
        if(index>=n){
            return 0;
        }
        if(index==n-1){
            return v[index];
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int incl = v[index] + solve(index+2,v,dp);
        int excl = solve(index+1,v,dp);
        dp[index] = max(incl,excl);
        return dp[index];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]; 
        vector<int> v1(n-1); // include 0th index
        vector<int> v2(n-1); // exclude 0th index

        for(int i=0;i<n;i++){
            if(i!=0){
               v2[i-1] = nums[i];
            }
            if(i!=n-1){
                v1[i] = nums[i];
            }
        }

        vector<int> dp(n+1,-1);

        int ans1 = solve(0,v1,dp);
        dp.assign(n,-1);
        int ans2 = solve(0,v2,dp);

        return max(ans1,ans2);
    }
};