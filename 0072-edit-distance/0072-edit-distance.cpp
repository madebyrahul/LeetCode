class Solution {

    int solve(string &a,string &b){
        int n = a.length();
        int m = b.length();
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);

        for(int j=0;j<m;j++){
            next[j] = m-j;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                curr[m] = n-i;
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }else{
                    int insertAns = 1 + curr[j+1];
                    int deleteAns = 1 + next[j];
                    int replaceAns = 1 + next[j+1];
                    ans = min(insertAns , min(deleteAns , replaceAns));
                }
                curr[j] =  ans;
            }
            next = curr;
        }

        return next[0];
    }

public:
    int minDistance(string word1, string word2) {
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }

        return solve(word1,word2);
    }
};