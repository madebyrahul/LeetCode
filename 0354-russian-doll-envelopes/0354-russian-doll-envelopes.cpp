class Solution {

    static bool comparison(const vector<int> &a,const vector<int> &b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }

    void extractCol(vector<vector<int>>& envelopes,vector<int>& nums,int col){
        for(const auto &v : envelopes){
            nums.push_back(v[col]);
        }
    }

    int solve(vector<int>& nums){
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comparison);
        vector<int> nums;
        extractCol(envelopes,nums,1);
        return solve(nums);
    }
};