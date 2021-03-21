class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }

        
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }

        return n - 1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }

        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};