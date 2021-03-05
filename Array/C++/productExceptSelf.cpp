class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() < 1) {
            return {};
        }

        int n = nums.size();
        vector<int> left_prod(n, 0);
        vector<int> right_prod(n, 0);

        vector<int> result(n);

        left_prod[0] = 1;
        for (int i = 1; i < n; i++) {
            left_prod[i] = nums[i - 1] * left_prod[i - 1];
        }

        right_prod[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right_prod[i] = nums[i + 1] * right_prod[i + 1];
        }


        for (int i = 0; i < n; i++) {
            result[i] = left_prod[i] * right_prod[i];
        }

        return result;
    }
};