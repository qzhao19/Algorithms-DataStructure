class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return n;
        }

        int slow_ptr = 1;

        for (int fast_ptr = 2; fast_ptr < n; fast_ptr++) {
            if (nums[slow_ptr - 1] != nums[fast_ptr]) {
                nums[++slow_ptr] = nums[fast_ptr];
            }
        }

        return slow_ptr + 1;
    }
};