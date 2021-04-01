class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash_set;
        int left = 0, max_substr_length = 0;

        if (s.size() == 0) {
            return 0;
        }
        
        for (int i = 0; i < s.size(); i++) {
            while (hash_set.find(s[i]) != hash_set.end()) {
                hash_set.erase(s[left]);
                left++;
            }
            hash_set.insert(s[i]);
            max_substr_length = max(max_substr_length, i - left + 1);
        }

        return max_substr_length;
    }
};