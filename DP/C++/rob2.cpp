class Solution {
public:
    int rob(vector<int> &nums, int begin, int end) {
        int dp_0 = nums[begin], dp_1 = max(nums[begin], nums[begin + 1]);
        int dp_i;

        if (begin == end) {
            return nums[begin];
        }

        for (int i = begin + 2; i <= end; i++) {
            dp_i = max(dp_0 + nums[i], dp_1);
            dp_0 = dp_1;
            dp_1 = dp_i;
        }

        return dp_i;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) {
            return 0;
        }

        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        if (n == 3) {
            return max(nums[0], max(nums[1], nums[2]));
        } 

        return max(rob(nums, 0, n-2), rob(nums, 1, n - 1));
    }

};