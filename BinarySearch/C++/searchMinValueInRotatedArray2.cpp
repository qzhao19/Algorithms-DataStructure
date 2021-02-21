class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n < 1 || n > 5e+4) {
            return 0;
        }

        int left = 0, right = n - 1;
        int mid;

        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            else if (nums[mid] == nums[right]) {
                right -= 1;
            }
        }

        return nums[left];
    }
};