class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {};
        int col[9][9] = {};
        int box[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] != '.') {
                    if (row[i][board[i][j] - '1']++) return false;
                    if (col[j][board[i][j] - '1']++) return false;
                    if (box[(i / 3) * 3 + (j / 3)][board[i][j] - '1']++) return false;
                }
            }
        }

        return true;

    }
};