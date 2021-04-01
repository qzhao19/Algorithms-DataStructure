/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Accepted
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        
        if (len < 1){
            return;
        }
        
        int pivot = len - 2;
        
        for (; pivot >= 0; pivot--){
            if (nums[pivot] < nums[pivot + 1]){
                break;
            }
        }
        if (pivot < 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = len - 1; ; i--){
            if (nums[pivot] < nums[i]){
                swap(nums[pivot], nums[i]);
                break;
            } 
        }
        reverse(nums.begin() + pivot + 1, nums.end());
        
        
    }
};