class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int cur_row = 0;
        string result;
        bool downing = false;
        vector<string> rows(min(numRows, int(s.length())));

        for (auto c : s) {
            rows[cur_row].push_back(c);
            if (cur_row == 0 || cur_row == numRows - 1) {
                downing = !downing;
            }
            cur_row += downing ? 1 : -1;
        }

        for (auto row : rows) {
            result += row;
        }

        return result;

    }
};