class Solution {
public:

    int div(long x, long y) {
        if (x < y) {
            return 0;
        }

        long y1 = y;
        long count = 1;

        while ((y1 << 1) <= x) {
            count *= 2;
            y <<= 1;
        }

        return count + div(x - y1, y);
    }

    int divide(int dividend, int divisor) {

        if (dividend < INT_MIN || dividend > INT_MAX || divisor < INT_MIN || divisor > INT_MAX) {
            return INT_MAX;
        }

        /*
        if (divisor == 1) {
            return dividend;
        } else if (divisor == -1) {
            return -dividend;
        }*/

        if (divisor == 0) {
            return INT_MAX;
        }

        int sign = (dividend >> 31) ^ (divisor >> 31);
        
        int ans = div(fabs((long)dividend), fabs((long)divisor));

        return sign == 0 ? ans : -ans;
    }
};