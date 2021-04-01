class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 1 || n > 1e+5) {
            return 0;
        }

        int left = 0, right = n - 1;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (target > nums[mid]) {
                left = mid + 1;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};