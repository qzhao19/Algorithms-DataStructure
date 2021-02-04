class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

public:

    void backtrack(int n, int k, int begin) {
        if (path.size() == k) {
            result.push_back(path);
            return ;
        }

        for (int i = begin; i <= n; i++) {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);

        return result;
    }
};