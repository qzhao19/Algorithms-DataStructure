class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 1 || n > 3e+5) {
            return 0;
        }

        int sum = 0;
        vector<int> max_left(n);
        vector<int> max_right(n);

        max_left[0] = height[0];
        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], height[i]);
        }

        max_right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i + 1], height[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            int min_h = min(max_left[i], max_right[i]);
            if (min_h > height[i]) {
                sum += (min_h - height[i]);
            }
        }

        return sum;
    }
};

class Solution {
public:
    int trap(vector<int>& height)
    {
        int sum = 0;
        int n = height.size();
        for (int i = 1; i < n - 1; i++) {
            int max_left = 0, max_right = 0;
            for (int j = i - 1; j >= 0; j--) { //Search the left part for max bar size
                max_left = max(max_left, height[j]);
            }
            for (int j = i + 1; j < n; j++) { //Search the right part for max bar size
                max_right = max(max_right, height[j]);
            }

            int min_h = min(max_left, max_right);
            if (min_h > height[i]) {
                sum += (min_h - height[i]);
            }

        }
        return sum;
    }
};


