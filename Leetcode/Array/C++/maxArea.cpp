class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }

        int max_area = INT_MIN;
        int left = 0, right = n - 1;

        while (left < right) {
            int min_height = min(height[left], height[right]);
            max_area = max(max_area, min_height * (right - left));

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return max_area;
    }
};