class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // checkout exceptional case

        if (nums.size() == 0){
            return -1;
        }

        // define vars 
        int cur_sum = -1;
        int max_sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++){
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int max_sum = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum > max_sum) {
                    max_sum = sum;
                }
            }
        }

        return max_sum;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        
        vector<int> dp(n);
        dp[0] = nums[0];
        int max_sum = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            max_sum = max(dp[i], max_sum);
        }

        return max_sum;
    }
};