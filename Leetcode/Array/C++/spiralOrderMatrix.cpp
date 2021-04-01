class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        vector<int> ans;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;

        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; j++){
                ans.push_back(matrix[top][j]);
            }
            for (int i = top + 1; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            if (left < right && top < bottom) {
                for (int j = right - 1; j > left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                for (int i = bottom; i > top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }

        return ans;

    }
};