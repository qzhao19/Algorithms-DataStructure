class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtrack(vector<int> &candidates, int target, int begin) {
        if (target == 0) {
            result.push_back(path);
            return ;
        }

        for (int i = begin; i < candidates.size(); i++) {
            if (target - candidates[i] < 0) {
                return ;
            }

            if (i > begin && candidates[i] == candidates[i - 1]) {
                continue;
            }

            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n < 1) {
            return {};
        }

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return result;
    }
};