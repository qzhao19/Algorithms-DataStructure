class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        if (n1 * n2 == 0) {
            return n1 + n2;
        } 

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j < dp[0].size(); j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;

                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
                }
            }
        }

        return dp[n1][n2];
    }
};