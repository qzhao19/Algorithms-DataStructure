class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() < 1) {
            return {};
        }

        map<int, int> hash_map;
        vector<int> result;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            hash_map[nums[i]]++;
        }

        map<int, int> :: iterator iter;
        for (iter = hash_map.begin(); iter != hash_map.end(); iter++) {
            if (iter -> second > (n/3)) {
                result.push_back(iter -> first);
            }
        }

        return result;
    }
};