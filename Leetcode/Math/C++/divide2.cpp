class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign;

        if ((dividend ^ divisor) < 0) {
            sign = 0;
        } 
        else {
            sign = 1;
        }

        long abs_dividend = abs(dividend), abs_divisor = abs(divisor);
        if (abs_dividend < abs_divisor) {
            return 0;
        }
        long result = 0, sum = 1; 
        long tmp_abs_divisor = abs_divisor;

        while ((abs_divisor << 1) < abs_dividend) {
            abs_divisor <<= 1;
            sum <<= 1;
        }

        while (abs_dividend >= tmp_abs_divisor) {
            abs_dividend -= abs_divisor;
            result += sum;

            while (abs_divisor > abs_dividend) {
                abs_divisor >>= 1;
                sum >>= 1;
            }
        }

        if (sign == 0) {
            if (-result < INT_MIN) {
                return INT_MIN;
            }
            else {
                return -result;
            }
        }
        else {
            if (result > INT_MAX) {
                return INT_MAX;
            }
            else {
                return result;
            }
        }



    }
};