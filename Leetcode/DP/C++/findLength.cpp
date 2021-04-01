class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len_A = A.size(), len_B = B.size();
        if (len_A < 1 || len_A > 1e+3 || len_B < 1 || len_B > 1e+3) {
            return 0;
        }

        int max_length = 0;
        vector<vector<int>> dp(len_A + 1, vector<int>(len_B + 1, 0));

        for (int i = 1; i <= len_A; i++) {
            for (int j = 1; j <= len_B; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                max_length = max(max_length, dp[i][j]);
            }
        }

        return max_length;
    }
};