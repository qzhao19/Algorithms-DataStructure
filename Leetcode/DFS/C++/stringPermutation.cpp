class Solution {
private:
    vector<string> ans;
    vector<bool> status;
    string str;
public:

    void backtrack(string s, int start) {
        if (s.size() == start) {
            ans.push_back(str);
            return ;
        }

        for (int i = 0; i < s.size(); i++) {
            if (status[i]) {
                continue;
            }

            if(i > 0 && s[i] == s[i-1] && status[i-1] == false) {
                continue;
            }

            str.push_back(s[i]);
            status[i] = true;
            backtrack(s, start + 1);
            str.pop_back();
            status[i] = false;
        }
    }

    vector<string> permutation(string s) {
        int n = s.size();
        status.resize(n, false);

        sort(s.begin(), s.end());
        backtrack(s, 0);

        return ans;
    }
};