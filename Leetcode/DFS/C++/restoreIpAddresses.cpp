class Solution {
private:
    string path;
    vector<string> result;

public:
    int checkIfIpSegment(string &s, int left, int right) {
        int len = right - left + 1;

        if (len > 1 && s[left] == '0') {
            return -1;
        }

        int result = 0;
        for (int i = left; i <= right; i++) {
            result = result * 10 + s[i] - '0';
            // cout << result <<endl;
        }

        if (result > 255) {
            return -1;
        }

        return result;
    }

    void backtrack(string &s, int len, int begin, int n_splits) {
        if (len == begin) {
            if (n_splits == 4) {
                path.pop_back();
                //path += ".";
                result.push_back(path);
            }
            return ;
        }

        if (len - begin < (4 - n_splits) || len - begin > 3 * (4 - n_splits)) {
            return ;
        }

        for (int i = 0; i < 3; i++) {
            if (begin + i >= len) {
                break;
            }

            int ip_segment = checkIfIpSegment(s, begin, begin + i);
            if (ip_segment != -1) {
                path += (to_string(ip_segment) + '.');
                backtrack(s, len, begin + i + 1, n_splits + 1);
                path.pop_back();
            }
        } 
    }


    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if (len < 4 || len > 12) {
            return {};
        }

        backtrack(s, len, 0, 0);

        return result;
    }
};