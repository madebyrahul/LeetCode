class Solution {

    int solve(string &str,string &pattern){
        vector<int> curr(pattern.length()+1,0);
        vector<int> prev(pattern.length()+1,0);
        prev[0] = true;

        for(int j=1;j<=pattern.length();j++){
            bool flag = true;
            for(int k=1;k<=j;k++){
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i=1;i<=str.length();i++){
            for(int j=1;j<=pattern.length();j++){
                  if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
                     curr[j] = prev[j-1];
                    }else if(pattern[j-1] == '*'){
                     curr[j] = ( prev[j] || curr[j-1] );
                    }else{
                     curr[j] = false;
                    }
            }
            prev = curr;
        }
        
        return prev[pattern.length()];

    }

public:
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};