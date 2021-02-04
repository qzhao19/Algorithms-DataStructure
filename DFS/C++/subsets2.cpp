class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backtrack(vector<int> &nums, int begin) {
        result.push_back(path);

        for (int i = begin; i < nums.size(); i++) {
            if (i > begin && nums[i] == nums[i - 1]) {
                continue;
            }

            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        backtrack(nums, 0);

        return result;

    }
};