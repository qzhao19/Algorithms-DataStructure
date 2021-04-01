class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int result = 0;
        int index = 0;

        unordered_map<char, int> hash_map;

        for (int i = 0; i < keyboard.size(); i++) {
            hash_map[keyboard[i]] = i;
        }

        for (auto w : word) {
            result += abs(index - hash_map[w]);
            index = hash_map[w];
        }

        return result;
    }
};