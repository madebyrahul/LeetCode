class Solution {

    int solve(vector<int>& a){
        int n = a.size();
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || a[curr] > a[prev]){
                    take = 1 + nextRow[curr+1];
                }
                int notTake = 0 + nextRow[prev+1];
                currRow[prev+1] = max(take,notTake);
            }
            nextRow = currRow;
        }
        
        return nextRow[0];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums);
    }
};