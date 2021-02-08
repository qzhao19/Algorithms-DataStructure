class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        double eps = 1e-6;
        vector<char> operators = {'+', '-', '*', '/'};
        vector<double> nums1(nums.begin(), nums.end());
        return dfs(nums1, operators, eps);
    }

    bool dfs(vector<double> &nums, vector<char> &operators, double eps) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24) < eps;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) {
                    continue; // if nums[i] == nums[j] which means the same number
                }
                vector<double> tmp;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        tmp.push_back(nums[k]);
                    }
                }

                for (char opt : operators) {
                    if ((opt == '+' || opt == '*') && i > j) {
                        continue;
                    }
                    if (opt == '/' && nums[j] < eps) {
                        continue;
                    }
                    switch(opt) {
                        case '+': tmp.push_back(nums[i] + nums[j]); break;
                        case '-': tmp.push_back(nums[i] - nums[j]); break;
                        case '*': tmp.push_back(nums[i] * nums[j]); break;
                        case '/': tmp.push_back(nums[i] / nums[j]); break;
                    }

                    if (dfs(tmp, operators, eps)) {
                        return true;
                    }
                    tmp.pop_back();
                }
            }
        }
        return false;
    }
};