class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }

        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            else if (nums[mid] == nums[right]) {
                right--;
            }
        }

        return nums[left];
    }
};