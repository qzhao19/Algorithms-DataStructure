class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() < 1) {
            return {};
        }

        vector<int> result;
        unordered_map<int, int> hash_map;

        for (auto num : nums) {
            hash_map[num]++;
        }

        unordered_map<int, int> :: iterator iter;
        for (iter = hash_map.begin(); iter != hash_map.end(); iter++) {
            if (iter -> second == 2) {
                result.push_back(iter -> first);
            }
        }

        return result;
    }
};