class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        if (nums.size() < 1) {
            return {};
        }

        int n = nums.size();
        vector<int> result(n);
        int i = 0;

        for (auto num : nums) {
            if (num % 2 == 0) {
                result[i] = num;
                i += 2;
            }
        }

        i = 1;
        for (auto num : nums) {
            if (num % 2 != 0) {
                result[i] = num;
                i += 2;
            }
        }

        return result;
    }
};