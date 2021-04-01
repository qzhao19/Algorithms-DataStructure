class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // method 1: sort

        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++){
            if (nums[i - 1] == nums[i]){
                return nums[i];
            }
        }
        return -1;
    }
};
