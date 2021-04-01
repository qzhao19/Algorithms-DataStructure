class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n_rows = obstacleGrid.size(), n_cols = obstacleGrid[0].size();

        if (n_rows == 0 || n_cols == 0) {
            return 0;
        }

        vector<vector<int>> dp(n_rows, vector<int>(n_cols, 0));

        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                    }
                    else if (i == 0) {
                        dp[i][j] = dp[i][j-1];
                    }
                    else if (j == 0) {
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1] + dp[i-1][j];
                    }
                }
            }
        }

        return dp[n_rows-1][n_cols-1];
    }
};