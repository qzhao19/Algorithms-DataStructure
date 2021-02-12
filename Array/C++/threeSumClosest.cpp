class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        if (nums.size() <= 0) {
            return 0;
        }
        int ans = 0;
        int closed_val = INT_MAX;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int cur_sum = nums[i] + nums[left] + nums[right];
                if (cur_sum == target) {
                    ans = cur_sum;
                    return ans;
                }
                else if (cur_sum < target) {
                    if (target - cur_sum < closed_val) {
                        // closed_val = min(target - cur_sum, closed_val);
                        // ans = cur_sum;
                        closed_val = target - cur_sum;
                        ans = cur_sum;
                    }
                    left++;
                } else { // cur_sum > target
                    if (cur_sum - target < closed_val) {
                        closed_val = cur_sum - target;
                        ans = cur_sum;
                    }
                    right--;
                }
            }
        }

        return ans;
    }
};