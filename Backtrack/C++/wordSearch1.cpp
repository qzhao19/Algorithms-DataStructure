class Solution {
private:
    bool is_used = false;
public:
    bool backtrack(vector<vector<char>> &board, string word, int begin, int row, int col) {
        int n_rows = board.size(), n_cols = board[0].size();

        if (word.size() == begin) {
            is_used = true;
            return true;
        }

        if (row < 0 || row >= n_rows || col < 0 || col >= n_cols || board[row][col] != word[begin]) {
            return false;
        }

        bool is_used_top, is_used_bottom, is_used_left, is_used_right;

        if (is_used == false) {
            char tmp = board[row][col];
            board[row][col] = '.';
            is_used_top = backtrack(board, word, begin + 1, row - 1, col);
            is_used_bottom = backtrack(board, word, begin + 1, row + 1, col);
            is_used_left = backtrack(board, word, begin + 1, row, col - 1);
            is_used_right = backtrack(board, word, begin + 1, row, col + 1);
            board[row][col] = tmp;

            return is_used_top || is_used_bottom || is_used_left || is_used_right;
        }

        return true;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n_chars = word.size();
        int n_rows = board.size(), n_cols = board[0].size();

        if (n_chars < 1 || n_chars > 1e+3) {
            return false;
        }
        if (n_rows < 1 || n_rows > 200) {
            return false;
        }

        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;

    }
};