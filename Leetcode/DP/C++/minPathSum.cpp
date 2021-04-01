class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n_rows = grid.size(), n_cols = grid[0].size();

        if (n_rows == 0 || n_cols == 0) {
            return 0;
        }

        vector<vector<int>> dp(n_rows, vector<int>(n_cols, 0));

        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else if (i == 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if (j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                }
            }
        }
        return dp[n_rows-1][n_cols-1];

    }
};