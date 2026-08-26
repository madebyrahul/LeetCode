class Solution {

    class node{
        public:
        int val;
        int row;
        int col;
        node(int d,int i,int j){
            val = d;
            row = i;
            col = j;
        }
    };

    class compare{
        public:
        bool operator()(node* a,node* b){
            return a->val > b->val;
        }
    };

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*,vector<node*>,compare> minHeap;
        int currMin = INT_MAX , currMax = INT_MIN;
        int size = nums.size();
        for(int i =0;i<size;i++){
            int val = nums[i][0];
            currMin = min(currMin,val);
            currMax = max(currMax,val);
            minHeap.push(new node(val,i,0));
        }
        vector<int> ans(2);
        ans[0] = currMin; // final min
        ans[1] = currMax; // final max
        while(!minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();
            currMin = temp->val;

            if((currMax - currMin) < (ans[1] - ans[0])){
                ans[1] = currMax;
                ans[0] = currMin;
            }
            
            if(temp->col + 1 < nums[temp->row].size()){
                currMax = max(currMax,nums[temp->row][temp->col + 1]);
                minHeap.push(new node(nums[temp->row][temp->col + 1],temp->row,temp->col + 1));
            }else{
                break;
            }
        }
        return ans;
    }
};