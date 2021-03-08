class Solution {
private:
    string path;
    vector<string> result;
public:
    bool isIpAddressses(string s) {
        if (s.empty() || s.length() > 1 && s[0] == '0') {
            return false;
        }

        int num = stoi(s);

        return num >= 0 && num <= 255; 
    }

    void backtrack(string s, int begin) {
        if (begin == 4) {
            if (s.empty() == true) {
                result.push_back(path);
            }
            return ;
        }

        if (begin > 0) {
            path += '.';
        }

        for (int i = 1; i <= 3 && i <= s.size(); i++) {
            string cur_s = s.substr(0, i);
            if (isIpAddressses(cur_s) == true) {
                path += cur_s;
                backtrack(s.substr(i), begin + 1);
                path.erase(path.size() - i);
            }
        }

        if (begin > 0) {
            path.erase(path.end() - 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);

        return result;
    }
};