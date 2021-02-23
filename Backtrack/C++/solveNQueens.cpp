class Solution {
private:
    vector<vector<string>> result;
public:
    bool validQueen(vector<string> &board, int row, int col) {
        int n = board.size();

        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtrack(vector<string> &board, int row) {
        int n = board.size();
        if (n == row) {
            result.push_back(board);
        }

        for (int col = 0; col < n; col++) {
            if (validQueen(board, row, col) == false) {
                continue;
            }
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n <1 || n > 9) {
            return result;
        }
        vector<string> board(n, string(n, '.'));

        backtrack(board, 0);

        return result;
    }
};



