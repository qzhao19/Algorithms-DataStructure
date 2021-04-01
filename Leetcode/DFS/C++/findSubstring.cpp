class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0 || words.size() == 0) {
            return {};
        }

        int j;
        int word_length = words[0].size(), word_count = words.size();
        unordered_map<string, int> hash_map, found_map;
        vector<int> ans;

        for (auto &word : words) {
            ++hash_map[word];
        }

        string substr = "";
        for (int i = 0; i + word_count * word_length <= s.size(); i++) {
            for (j = i; j < i + word_count * word_length; j += word_length) {
                substr = s.substr(j, word_length);
                if (hash_map.find(substr) == hash_map.end()) {
                    break;
                }
                ++found_map[substr];
            }

            if (j == i + word_length * word_count && found_map == hash_map) {
                ans.push_back(i);
            }
            found_map.clear();
        }

        return ans;
        
    }
};