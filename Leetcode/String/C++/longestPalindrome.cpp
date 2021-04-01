class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return "";
        }
        string result;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int index = 0; index < n; index++) {
            for (int i = 0; i + index < n; i++) {
                int j = index + i;

                if (index == 0) {
                    dp[i][j] = 1;
                }
                else if (index == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                }

                if (dp[i][j] && result.length() < index + 1) {
                    result = s.substr(i, index + 1);
                }
            }
        }

        return result;
    }
};