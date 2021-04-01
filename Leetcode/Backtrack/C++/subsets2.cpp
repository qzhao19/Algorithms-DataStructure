class Solution {
private:
    vector<vector<int>> subset;
    vector<int> path;
public:
    void backtrack(vector<int> &nums, int begin) {
        subset.push_back(path);

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
        int n = nums.size();
        if (n < 1) {
            return {};
        }

        sort(nums.begin(), nums.end());

        backtrack(nums, 0);

        return subset;
    }
};