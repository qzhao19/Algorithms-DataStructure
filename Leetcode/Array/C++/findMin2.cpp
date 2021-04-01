class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] < nums[right]) {
                right = mid;
            }
            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] == nums[right]) {
                right -= 1;
            }
        }

        return nums[left];
    }
};