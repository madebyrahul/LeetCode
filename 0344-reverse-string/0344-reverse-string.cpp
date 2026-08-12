class Solution {
public:
    void reverseString(vector<char>& arr) {
        stack<char> s;
        for(int i=0;i<arr.size();i++){
            char temp = arr[i];
            s.push(temp);
        }
        int i=0;
        while(!s.empty() && i<arr.size()){
            char ch = s.top();
            arr[i++] = ch;
            s.pop();
        }
    }
};