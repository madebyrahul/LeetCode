class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int i=0,j=0;
        while(j<nums.size()){
            while( !q.empty() &&  nums[q.back()] < nums[j]){
                q.pop_back();
            }
            q.push_back(j);
            if(j-i+1 == k){
                ans.push_back(nums[q.front()]);
                if(q.front() == i){
                    q.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};