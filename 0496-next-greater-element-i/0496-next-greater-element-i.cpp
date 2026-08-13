class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        s.push(-1);
        unordered_map<int,int> m;
        for(int i=nums2.size()-1;i>=0;i--){
            int curr = nums2[i];
            while(!s.empty() && s.top()<=curr){
                s.pop();
            }
            m[nums2[i]] = s.empty() ? -1 : s.top();;
            s.push(nums2[i]);
        }
        vector<int> v(nums1.size());
        for(int i=0;i<nums1.size();i++){
            int curr = nums1[i];
            int nextGreat = m[curr];
            v[i] = nextGreat;
        }
        return v;
    }
};