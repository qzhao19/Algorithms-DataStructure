class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest_pos = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i <= farthest_pos) {
                farthest_pos = max(farthest_pos, i + nums[i]);
            }
        }

        if (farthest_pos >= n - 1) {
            return true;
        }

        return false;
    }
};