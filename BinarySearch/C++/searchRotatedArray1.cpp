class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 1 || n > 5e+3) {
            return -1;
        }

        int left = 0, right = n - 1;
        int mid;
        while (left <= right) {
            mid= left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if (nums[mid] > nums[right]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};