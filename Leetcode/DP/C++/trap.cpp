class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> left_max_h(n);
        vector<int> right_max_h(n);

        if (height.size() == 0) {
            return 0;
        }
        left_max_h[0] = height[0];
        for (int i = 1; i < n - 1; i++) {
            left_max_h[i] = max(left_max_h[i-1], height[i]);
        }

        right_max_h[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            right_max_h[j] = max(right_max_h[j+1], height[j]);
        }

        for (int i = 1; i < n - 1; i++) {
            int min_h = min(left_max_h[i], right_max_h[i]);
            if (min_h > height[i]) {
                ans += (min_h - height[i]);
            }
        }
        return ans;
    }
};