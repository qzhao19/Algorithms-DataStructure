class Solution {
public:
    int longestValidParentheses(string s) {
        int max_length = 0;
        stack<int> stk;
        stk.push(-1);

        if (s.size() == 0) {
            return 0;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    max_length = max(max_length, i - stk.top());
                }
            }
        }

        return max_length;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        int max_length = 0;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                max_length = max(max_length, dp[i]);
            }
        }

        return max_length;
    }
};