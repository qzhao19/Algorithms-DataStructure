class Solution {
private:
    vector<vector<int>> permutations;
    vector<bool> status;
    vector<int> path;

public:
    void backtrack(vector<int> &nums, int begin) {
        int n = nums.size();
        if (begin == n) {
            permutations.push_back(path);
            return ;
        }

        for (int i = 0; i < n; i++) {
            if (status[i] == true) {
                continue;
            }

            path.push_back(nums[i]);
            status[i] = true;
            backtrack(nums, begin + 1);
            path.pop_back();
            status[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n < 1 || n >1e+5) {
            return permutations;
        }

        status.resize(n, false);

        backtrack(nums, 0);

        return permutations;
    }
};