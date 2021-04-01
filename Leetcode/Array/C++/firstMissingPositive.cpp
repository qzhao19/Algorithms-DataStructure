class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // hash method

        int n = nums.size(), ans = 0;
        if (n == 0) {
            return 1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int abs_num = abs(nums[i]);
            if (abs_num <= n) {
                nums[abs_num - 1] = -abs(nums[abs_num - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};