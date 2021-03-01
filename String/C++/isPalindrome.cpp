class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n < 1) {
            return true;
        }

        string strs;

        for (auto c : s){
            if (isalnum(c)) {
                strs += tolower(c);
            }
        }

        int left = 0, right = strs.length() - 1;

        while (left < right) {
            if (strs[left] == strs[right]) {
                left++;
                right--;
            }
            else {
                return false;
            }
        }

        return true;
    }
};