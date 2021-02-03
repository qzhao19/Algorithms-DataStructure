class Solution {
private:
    string str;
    vector<string> result;
public:
    bool isValidIp(string s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) {
            return false;
        }

        int num = stoi(s);

        return num >= 0 && num <= 255;
    }

    void backtrack(string s, int begin) {
        if (begin == 4) {
            if (s.empty() == true) {
                result.push_back(str);
            }
            return ;
        }

        if (begin > 0) {
            str += '.';
        }

        for (int i = 1; i <= 3 && i <= s.size(); i++) {
            string cur_s = s.substr(0, i);
            if (isValidIp(cur_s)) {
                str += cur_s;
                backtrack(s.substr(i), begin + 1);
                str.erase(str.size() - i);
            }
        }

        if (begin > 0) {
            str.erase(str.end() - 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);

        return result;
    }
};