class Solution {
public:
    /**int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    cnt++;
                }
            }
        }

        return cnt;
    }**/

    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();

        unordered_map<int, int> hash_map;
        hash_map[0] = 1;

        int prev_sum = 0, cnt = 0;

        for (auto &num : nums) {
            prev_sum += num;
            if (hash_map.find(prev_sum - k) != hash_map.end()) {
                cnt += hash_map[prev_sum - k];
            }
            hash_map[prev_sum]++;
        }

        return cnt;
    }
};