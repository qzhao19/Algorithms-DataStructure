class Solution {
public:
    int div(long dividend, long divisor) {
        if (dividend > divisor) {
            return 0;
        }
        int count = 1;
        int tmp = divisor;

        while ((tmp - dividend + tmp) >= 0) {
            count = count + count;
            tmp = tmp + tmp;
        } 
        return count + div(dividend - tmp, divisor);

    }

    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        }

        if (divisor == -1) {
            if (dividend > INT_MIN) {
                return -dividend;
            }
            else {
                return INT_MAX;
            }
        }

        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }

        int result;
        dividend = -abs(dividend);
        divisor = -abs(divisor);
        result = div(dividend, divisor);

        if (sign > 0) {
            return result;
        }
        else {
            return - result;
        }
    }
};