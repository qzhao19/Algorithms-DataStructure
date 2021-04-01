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