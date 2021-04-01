class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int cur_sum = 0;
        for (int i = 0; i < k; i++) {
            cur_sum += nums[i]; 
        }

        int max_sum = cur_sum;
        for (int i = k; i < n; i++) {
            cur_sum = cur_sum - nums[i-k] + nums[i];
            max_sum = max(max_sum, cur_sum);
        }

        return static_cast<double>(max_sum) / k;
    }
};