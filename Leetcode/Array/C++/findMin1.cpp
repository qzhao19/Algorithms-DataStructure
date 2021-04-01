class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        if (n == 1) {
            return nums[0];
        }

        if (nums[left] < nums[right]) {
            return nums[left];
        }
        
        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            if (nums[left] < nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;

    }
};