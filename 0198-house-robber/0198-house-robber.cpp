class Solution {

    int solve(vector<int> &nums){
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i=1;i<n;i++){
            int incl = nums[i] + prev2;
            int excl = 0 + prev1;
            int ans = max(excl,incl);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        // memory optimization
        return solve(nums);
    }
};