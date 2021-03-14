class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max_length = 1, cur_length = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            else if (nums[i] - nums[i - 1] == 1) {
                cur_length++;
                max_length = max(max_length, cur_length);
            }
            else {
                cur_length = 1;
            }
        }

        return max_length;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        unordered_set<int> hash_set;

        for (auto &num : nums) {
            hash_set.insert(num);
        }

        int max_length = 0;

        for (auto &num : nums) {
            if (hash_set.count(num - 1) == false) {
                int cur_num = num;
                int cur_length = 1;

                while (hash_set.count(cur_num + 1) == true) {
                    cur_num++;
                    cur_length++;
                }

                max_length = max(max_length, cur_length);
            }
        }

        return max_length;
    }
};