class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return {};
        }
        vector<vector<string>> result;

        unordered_map<string, vector<string>> hash_map;

        string cur_str;

        for (int i = 0; i < n; i++) {
            cur_str = strs[i];
            sort(cur_str.begin(), cur_str.end());
            hash_map[cur_str].push_back(strs[i]);
        }

        for (auto val : hash_map) {
            result.push_back(val.second);
        }

        return result;

    }
};