class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        string result = "";
        for (int i = 0; i < num.length(); i++) {
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

            if (k == 0) {
                result.push_back(stk.top()); 
            }
            stk.pop();
        }

        reverse(result.begin(), result.end());

        return result == "" ? "0" : result;
    }
};