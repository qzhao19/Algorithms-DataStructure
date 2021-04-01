class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), max_pos = 0, last_pos = 0, step = 0;

        for (int i = 0; i < n - 1; i++) {
            if (i <= max_pos) {
                max_pos = max(nums[i] + i, max_pos);
                if (i == last_pos) {
                    last_pos = max_pos;
                    ++step;
                }
            }
        }

        return step;
    }
};