class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
public:
    void backtrack(vector<int> &nums, int begin) {
        
        result.push_back(path);

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

        return result;
    }
};