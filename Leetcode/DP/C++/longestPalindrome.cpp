class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ans;

        for (int length = 0; length < n; length++) {
            for (int i =0; i + length < n; i++) {
                int j = i + length;

                if (length == 0) {
                    dp[i][j] = true;
                }
                else if (length == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
                }

                if (dp[i][j] && length + 1 > ans.size()) {
                    ans = s.substr(i, length + 1);
                }
            }
        }

        return ans;
    }
};
