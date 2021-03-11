class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 1) {
            return ;
        }

        int index = 0;
        int n = nums.size();
       
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[index]);
                index++;
            }
        }

    }
};