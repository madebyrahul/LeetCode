class Solution {

    bool solve(int total,int n,vector<int>& arr){
        int t = total/2;
        vector<int> curr(t+1,0);
        vector<int> next(t+1,0);
        curr[0] = 1;
        next[0] = 1;

        for(int index=n-1;index>=0;index--){
            for(int target=0;target<=t;target++){
                 bool incl=0;
                 if(target-arr[index] >=0){
                      incl = next[target-arr[index]];
                 }
                 bool excl = next[target];
                 curr[target] =  incl or excl;
            }
            next = curr;
        }

        return next[t]; 
        
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