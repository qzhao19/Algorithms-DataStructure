class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            }
            else {
                if (stk.empty()) return false;
                if (stk.top() == '(' && s[i] != ')') return false;
                if (stk.top() == '[' && s[i] != ']') return false;
                if (stk.top() == '{' && s[i] != '}') return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, char> rows[9], cols[9], boxes[9];

        // cout<< rows[1][1] << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && 
                    (rows[i][board[i][j]]++ || 
                     cols[j][board[i][j]]++ || 
                     boxes[i / 3 * 3 + j / 3][board[i][j]])) {
                        return false;
                    }
            }
        }

        return true;
    }
};