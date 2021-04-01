class Solution {
public:
    bool isPalindrome(int x) {
        int digit = 0, result = 0;

        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        while (x > result) {
            digit = x % 10;
            x /= 10;
            result = result * 10 + digit;
        }

        return result == x || result / 10 == x;
    }
};