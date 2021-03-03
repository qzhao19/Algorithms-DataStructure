class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backtrack(vector<int> &candidats, int target, int k, int begin) {
        if (k == 0 && target == 0) {
            result.push_back(path);
            return ;
        }

        for (int i = begin; i < candidats.size(); i++) {
            path.push_back(candidats[i]);
            backtrack(candidats, target - candidats[i], k - 1, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidats = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        backtrack(candidats, n, k, 0);

        return result;
    }
};