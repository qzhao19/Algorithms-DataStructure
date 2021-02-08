class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if (n < 2) {
            return {};
        }

        int left = 0, right = n - 1;

        vector<int> result;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            } 
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return result;
    }
};