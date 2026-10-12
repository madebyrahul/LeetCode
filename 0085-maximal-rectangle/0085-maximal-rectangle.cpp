class Solution {

    vector<int> nextSmaller(int* arr,int size){
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);
        for(int i=size-1;i>=0;i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top() == -1 ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(int* arr,int size){
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top() == -1 ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    int getMaxArea(int* arr,int size){
        vector<int> next(size);
        vector<int> prev(size);
        next = nextSmaller(arr,size);
        prev = prevSmaller(arr,size);
        int area = INT_MIN;
        for(int i=0;i<size;i++){
            int h = arr[i];
            next[i] = next[i] == -1 ? size : next[i];
            int w = next[i] - prev[i] -1;
            area = max(area,h*w);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int* height = new int[n]();
        int maxi = INT_MIN;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            maxi = max(maxi,getMaxArea(height,n));
        }
        delete[] height;
        return maxi;
    }
};