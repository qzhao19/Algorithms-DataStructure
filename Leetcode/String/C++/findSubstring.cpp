class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0 || words.size() == 0) {
            return {};
        }

        int n_words = words.size(), len_words = words[0].size();
        int j = 0;
        unordered_map<string, int> hash_map, found_map;
        vector<int> ans;

        for (int i = 0; i < n_words; i++) {
            ++hash_map[words[i]];
        }

        string str = "";

        for (int i = 0; i + n_words * len_words <= s.size(); i++) {
            for (j = i; j < i + n_words * len_words; j += len_words) {

                str = s.substr(j, len_words);

                if (hash_map.find(str) == hash_map.end()) {
                    break;
                }
                ++found_map[str];
            }

            if (j == i + len_words * n_words && found_map == hash_map) {
                ans.push_back(i);
            }
            found_map.clear();
        }

        return ans;


    }
};