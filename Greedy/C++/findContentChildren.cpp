class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cook = 0, child = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (child < g.size() && cook < s.size()) {
            if (g[child] <= s[cook]) {
                ++child;
            }
            ++cook;
        }

        return child;
    }
};