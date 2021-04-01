class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long long n1 = n;

        if (n < 0) {
            n1 = -n1;
            x = 1 / x;
        }

        while (n1 > 0) {
            if ((n1&1) == 1) {
                result = result * x;
            }
            x *= x;
            n1 >>= 1;
        }

        return result;
    }
};