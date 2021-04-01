class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_rows = matrix.size(), n_cols = matrix[0].size();
        if (n_rows < 0 || n_rows > 100 || n_cols < 0 || n_cols > 100) {
            return false;
        }

        int i = 0, j = n_cols - 1;
        while (i < n_rows && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }
            else if (target < matrix[i][j]) {
                j--;
            }
            else {
                i++;
            }
        }

        return false;
    }
};