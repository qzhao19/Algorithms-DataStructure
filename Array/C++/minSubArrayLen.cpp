class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n < 1 || n > 1e+9) {
            return 0;
        }

        int sub_array_len = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cur_sum = 0;
            for (int j = i; j < n; j++) {
                cur_sum += nums[j];
                if (cur_sum >= target) {
                    sub_array_len = min(sub_array_len, j - i + 1);
                    break;
                }
            }
        }

        return sub_array_len == INT_MAX ? 0 : sub_array_len;
    }
};