class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i] % 2 == 0){
                m[nums[i]]++;
            }
        }
        int maxiFreq = 0;
        int ans = -1;
        for(auto val : nums){
           if(val % 2 != 0) continue;
           if(m[val] > maxiFreq || m[val] == maxiFreq && val < ans){
              maxiFreq = m[val];
              ans = val;
           }
        }
        return ans;
    }
};