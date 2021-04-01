class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return {};
        }
        vector<vector<int>> result;
        set<vector<int>> hash_set;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    hash_set.insert(tmp);
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        result = {hash_set.begin(), hash_set.end()};

        return result;
    }
};