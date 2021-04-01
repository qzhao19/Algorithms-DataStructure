class Solution {
private:
    vector<string> result;

public:

    void dfs(string str, int left, int right, int n) {
        if (left == n && right == n) {
            result.push_back(str);
            return ;
        }

        if (left < right) {
            return ;
        }

        if (left < n) {
            dfs(str + '(', left + 1, right, n);
        }

        if (right < n) {
            dfs(str + ')', left, right + 1, n);
        }
    }


    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }

        dfs("", 0, 0, n);

        return result;
    }
};