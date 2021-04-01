class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        if (n <= 0 || n >= 10000) {
            return false;
        }

        for (int begin = 0; begin < n; begin++) {
            for (int end = begin + 1; end < n; end++) {
                int sum = 0;
                for (int i = begin; i <= end; i++) {
                    sum += nums[i];
                    if (i >= 2 && (sum % k) == 0) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 0 || n >= 10000) {
            return false;
        }

        vector<int> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        
        for (int begin = 0; begin < n - 1; begin++) {
            for (int end = begin + 1; end < n; end++) {
                int cur_sum = prefix_sum[end] - prefix_sum[begin] + nums[begin];
                if (cur_sum == k || (k != 0 && cur_sum % k == 0)) {
                    return true;
                }
            }
        }

        return false;

    };


bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> hash_map;
        hash_map[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (k != 0) {
                sum %= k;
            }
            if (hash_map.find(sum) != hash_map.end()) {
                if (i - hash_map[sum] > 1) {
                    return true;
                }
            }
            else {
                hash_map[sum] = i;
            }
        }

        return false;
    }