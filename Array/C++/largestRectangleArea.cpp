class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;


        for(int left = 0; left < n; left++){
            int min_height = INT_MAX;
            for (int right = left; right < n; right++){
                min_height = min(min_height, heights[right]);

                ans = max(ans, min_height * (right - left + 1));
            }
        }
        return ans;
    }
};