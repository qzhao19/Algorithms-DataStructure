class Solution {
public:
    void dfs(vector<vector<char>> &grid, int row, int col) {
        int n_rows = grid.size(), n_cols = grid[0].size();

        if (row < 0 || row >= n_rows || col < 0 || col >= n_cols) {
            return ;
        }

        if (grid[row][col] != '1') {
            return ;
        }

        grid[row][col] = 2;
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col); 
        dfs(grid, row, col - 1); 
        dfs(grid, row, col + 1);


    }
    int numIslands(vector<vector<char>>& grid) {
        int n_rows = grid.size(), n_cols = grid[0].size();
        if (n_rows == 0 || n_cols == 0) {
            return 0;
        }

        int n_islands = 0;

        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    n_islands++;
                }
            }
        }
        return n_islands;
    }
};