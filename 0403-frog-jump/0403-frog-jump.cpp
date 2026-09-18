class Solution {

    bool solve(vector<int>& stones,int curr_stone_idx,int prevJump,
            unordered_map<int,int> &mp,vector<vector<int>> &dp){
        if(curr_stone_idx == stones.size()-1){
            return true;
        }

        if(dp[curr_stone_idx][prevJump] != -1){
            return dp[curr_stone_idx][prevJump];
        }

        bool result = false;
        for(int nextJump = prevJump-1;nextJump<=prevJump+1;nextJump++){
            if(nextJump > 0){
                int next_stone = stones[curr_stone_idx] + nextJump;
                if(mp.find(next_stone) != mp.end()){
                    result = result || solve(stones,mp[next_stone],nextJump,mp,dp);
                }
            }
        }
        return dp[curr_stone_idx][prevJump] =  result;
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,int> mp;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        if(stones[1] != 1){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[stones[i]] = i;
        }
        return solve(stones,0,0,mp,dp);
    }
};