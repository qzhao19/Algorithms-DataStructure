class Solution {
private:
    unordered_map<char, string> hash_map = {{'2', "abc"}, {'3', "def"}, 
                                            {'4', "ghi"}, {'5', "jkl"}, 
                                            {'6', "mno"}, {'7', "pqrs"}, 
                                            {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> result;
    string str;

public:

    void backtrack(string digits, int start) {
        if (digits.size() == start) {
            result.push_back(str);
            return ;
        }

        for (int i = 0; i < hash_map[digits[start]].size(); i++) {
            str.push_back(hash_map[digits[start]][i]);
            backtrack(digits, start + 1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        backtrack(digits, 0);

        return result;
    }
};