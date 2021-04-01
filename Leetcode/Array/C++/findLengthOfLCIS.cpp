class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        int cnt = 1, result = 1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] > nums[i]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            result = max(result, cnt);
        }

        return result;
    }
};