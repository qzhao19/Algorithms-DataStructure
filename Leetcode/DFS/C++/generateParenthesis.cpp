class Solution {

private:
    vector<string> result;
    string str;
public:
    void backtrack(int n, int left, int right) {
        if (left == n && right == n) {
            result.push_back(str);
            return;
        }

        if (left < right) {
            return ;
        }

        if (left < n) {
            str.push_back('(');
            backtrack(n, left + 1, right);
            str.pop_back();
        }

        if (right < n) {
            str.push_back(')');
            backtrack(n, left, right + 1);
            str.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }

        backtrack(n, 0, 0);

        return result;
    }
};