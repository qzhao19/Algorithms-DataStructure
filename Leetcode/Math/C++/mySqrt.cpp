class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        int left = 0, right = x / 2 + 1;
        int ans = 0;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if ((long long)mid * mid <= x) {
                ans = mid; 
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};