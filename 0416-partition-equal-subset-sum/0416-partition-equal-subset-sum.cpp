class Solution {

    bool solve(int index,int target,int n,vector<int>& arr,vector<vector<int>> &dp){
        if(index >= n) return false;
        if(target < 0) return false;
        if(target == 0) return true;

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool incl = solve(index+1,target-arr[index],n,arr,dp);
        bool excl = solve(index+1,target,n,arr,dp);
        return dp[index][target] =  incl or excl;
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(const int &i : nums){
            total += i;
        }
        if(total & 1) return false;
        int target = total/2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,target,n,nums,dp);
    }
};