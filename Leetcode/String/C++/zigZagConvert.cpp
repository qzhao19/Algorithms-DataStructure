class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int str_len = s.size();
        string result;

        for (int index = 0; index < numRows; index++) {
            int length = numRows * 2 - 2;
            if (index == 0 || index == numRows - 1) {
                for (int i = index; i < str_len; i += length) {
                    result.push_back(s[i]);
                }
            }
            else {
                for (int left = index, right = length - index; left < str_len; left += length, right += length) {
                    result.push_back(s[left]);
                    if (right < str_len) {
                        result.push_back(s[right]);
                    }
                }
            }
        }
        return result;

    }
};