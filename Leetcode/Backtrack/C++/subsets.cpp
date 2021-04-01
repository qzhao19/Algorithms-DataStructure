class Solution {
private:
    vector<vector<int>> subset;
    vector<int> path;
public:
    void backtrack(vector<int> &nums, int begin) {
        subset.push_back(path);

        for (int i = begin; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if (n < 1 || n > 10) {
            return {};
        }

        backtrack(nums, 0);

        return subset;
    }
};