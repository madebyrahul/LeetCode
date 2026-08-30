class Solution {
public:
    double myPow(double x, int n) {
        long y = abs(long(n));
        double ans = 1.0;
        while(y>=1){
            if(y&1){
                ans = ans*x;
            }
            x = x*x;
            y = y/2;
        }
        return n<0 ? 1/ans : ans;
    }
};