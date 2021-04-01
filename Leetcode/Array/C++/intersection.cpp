class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> hash_set = {nums1.begin(), nums1.end()};

        for (auto &num2 : nums2) {
            if (hash_set.find(num2) != hash_set.end()) {
                hash_set.erase(num2);
                result.push_back(num2);
            }
        }
        return result;

    }
};