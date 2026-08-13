class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == '('){
                count++;
            }
            if(ch == ')'){
                count--;
            }

            if(count == 1 && ch == '(' || count == 0){
                continue;
            }else{
                ans += ch;
            }

        }
        return ans;
    }
};