class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n; // Store n in long long to prevent integer overflow when n = INT_MIN
        if (nn < 0) {
            nn = -1 * nn;
        }
        
        double ans = 1.0;
        
        while (nn > 0) {
            if (nn % 2 == 1) { // If power is odd
                ans = ans * x;
                nn = nn - 1;
            } else { // If power is even
                x = x * x;
                nn = nn / 2;
            }
        }
        
        if (n < 0) {
            ans = (double)(1.0) / (double)(ans);
        }
        
        return ans;
    }
};
