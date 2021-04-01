class Solution {
public:
    void reverseArray(vector<int> &nums, int begin, int end) {
        while (begin < end) {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 1) {
            return ;
        }

        int n = nums.size();

        k %= n;

        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }
};