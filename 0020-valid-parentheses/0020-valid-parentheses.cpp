class Solution {

    bool match(char ch, char top){
        if( ch == ')' && top == '(' ){
            return true;
        }else if( ch == '}' && top == '{' ){
            return true;
        }else if( ch == ']' && top == '[' ){
            return true;
        }else{
            return false;
        }
    }

public:
    bool isValid(string s) {
         stack<char> st;
         for(int i=0;i<s.length();i++){
            char ch = s[i];
            if( ch == '(' || ch == '{' || ch == '[' ){
                st.push(ch);
            }else{
                if(!st.empty()){
                    if(match(ch,st.top())){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
         }
        
        return st.empty() ? true : false;

    }
};