class Solution {
public:
    string simplifyPath(string path) {
        stringstream str_stream(path);
        string result = "", tmp = "";

        vector<string> strs;

        while (getline(str_stream, tmp, '/')) {
            if (tmp == "" || tmp == ".") {
                continue;
            }
            else if (tmp == ".." && !strs.empty()) {
                strs.pop_back();
            }
            else if (tmp != "..") {
                strs.push_back(tmp);
            }
        }

        for (auto &str : strs) {
            result += "/" + str;
        }

        if (result.empty()) {
            return "/";
        }

        return result;
    }
};