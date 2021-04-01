class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        if (nums.size() < 1 || nums.size() > 1e+4) {
            return {};
        }

        int n = nums.size();
        int n_removed_vals = n - k;

        int left = 0, right = n - 1;

        while (n_removed_vals > 0) {
            if (x - nums[left] <= nums[right] - x) {
                right--;
            }
            else {
                left++;
            }
            n_removed_vals--;
        }

        vector<int> result;
        for (int i = left; i < left + k; i++) {
            result.push_back(nums[i]);
        }

        return result;
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        if (nums.size() < 1 || nums.size() > 1e+4) {
            return {};
        }

        int n = nums.size();
        int left = 0, right = n - k - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (x - nums[mid] <= nums[mid + k] - x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return vector<int>(nums.begin() + left, nums.begin() + left + k);
    }
};