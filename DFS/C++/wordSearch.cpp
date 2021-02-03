class Solution {
private:
    bool is_visited = false;
public:
    bool dfs(vector<vector<char>> &board, string word, int begin, int row, int col) {
        if (word.size() == begin) {
            is_visited = true;
            return true;
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[begin]) {
            return false;
        }

        bool is_visited_top, is_visited_bottom, is_visited_left, is_visited_right;

        if (is_visited == false) {
            char tmp = board[row][col];
            board[row][col] = '.';
            is_visited_top = dfs(board, word, begin + 1, row - 1, col);
            is_visited_bottom = dfs(board, word, begin + 1, row + 1, col);
            is_visited_left = dfs(board, word, begin + 1, row, col - 1);
            is_visited_right = dfs(board, word, begin + 1, row, col + 1);
            board[row][col] = tmp;

            return is_visited_top || is_visited_bottom || is_visited_left || is_visited_right;
        }
        return true;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n_rows = board.size(), n_cols = board[0].size();

        if (n_rows == 0 || n_cols == 0 || word.size() == 0) {
            return false;
        }

        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};