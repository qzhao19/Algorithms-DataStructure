class Solution {
private:
    vector<string> result;
    vector<bool> status;
    string path;
public:
    void backtrack(string s, int begin) {
        if (s.length() == begin) {
            result.push_back(path);
            return ;
        }

        for (int i = 0; i < s.length(); i++) {
            if (status[i] == true) {
                continue;
            }

            if (i > 0 && s[i] == s[i - 1] && status[i - 1] == true) {
                continue;
            }

            path += s[i];
            status[i] = true;
            backtrack(s, begin + 1);
            path.pop_back();
            status[i] = false;
        }
    }

    vector<string> permutation(string s) {
        int n = s.length();

        if (n < 1 || n > 8) {
            return {};
        }

        status.resize(n, false);
        
        sort(s.begin(), s.end());

        backtrack(s, 0);

        return result;
    }
};