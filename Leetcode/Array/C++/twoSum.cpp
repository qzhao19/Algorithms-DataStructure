class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        vector<int> result;

        if (nums.size() == 0) {
            return {};
        }
        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];
            if (hash_map.find(val) != hash_map.end() && hash_map[val] != i) {
                result.push_back(i);
                result.push_back(hash_map[val]);
                break;
            }
        }

        return result;
    }
};