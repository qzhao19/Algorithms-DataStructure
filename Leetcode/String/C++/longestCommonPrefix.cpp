class Solution {

private:
    string longestCommonPrefix(string &s1, string &s2) {
        int index = 0;
        while (index < min(s1.length(), s2.length()) && s1[index] == s2[index]) {
            index++;
        }

        return s1.substr(0, index);
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        string result = strs[0];

        for (int i = 1 ; i < strs.size(); i++) {
            result = longestCommonPrefix(result, strs[i]);
        }

        return result;
    }
};