class Solution {

    bool solve(int total,int n,vector<int>& arr){
        int t = total/2;
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int index=n-1;index>=0;index--){
            for(int target=0;target<=t;target++){
                 bool incl=0;
                 if(target-arr[index] >=0){
                      incl = dp[index+1][target-arr[index]];
                 }
                 bool excl = dp[index+1][target];
                 dp[index][target] =  incl or excl;
            }
        }

        return dp[0][t]; 
        
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(const int &i : nums){
            total += i;
        }
        if(total & 1) return false;
        int n = nums.size();
        return solve(total,n,nums);
    }
};