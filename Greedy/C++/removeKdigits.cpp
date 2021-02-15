class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        string result = "";
        int n = num.length();

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top() > num[i] && k > 0) {
                stk.pop();
                k--;
            }

            if (stk.empty() && num[i] == '0') {
                    continue;
            }
            stk.push(num[i]);
        }

        while (!stk.empty()) {
            if (k > 0) {
                k--;
            }
            else if (k == 0) {
                result.push_back(stk.top());
            }
            stk.pop();
        }

        reverse(result.begin(), result.end());

        return result == "" ? "0" : result;

    }
};


class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int n = num.length();

        for (int i = 0; i < n; i++) {
            while (!result.empty() && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }

            if (result.empty() && num[i] == '0') {
                continue;
            }
            result.push_back(num[i]);
        }

        while (!result.empty() && k > 0) {
            result.pop_back();
            k--;
        }

        // reverse(result.begin(), result.end());

        return result == "" ? "0" : result;
    }
};