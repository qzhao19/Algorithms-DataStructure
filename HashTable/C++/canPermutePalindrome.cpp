class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < s.length(); i++) {
            hash_map[s[i]]++;
        }
        int cnt = 0;

        for (auto map : hash_map) {
            if (map.second % 2 != 0) {
                cnt++;
            }
        }

        return cnt <= 1;
    }
};