class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // method 2: set

        unordered_set<int> set;

        for (int i = 0; i < nums.size(); i++){
            if (!set.insert(nums[i]).second){
                return nums[i];
            }
        } 
        return -1;
    }
};
