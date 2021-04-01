class Solution {
public:
    bool find(vector<vector<int>> &matrix, int target, int i, bool stop) {
        int n = matrix[0].size();
        int left = 0, right = n - 1;
        int mid;
        if (matrix[i][0] > target) {
            stop = true;
        }
        else {
            while (left <= right) {
                mid = left + ((right - left) >> 1);
                if (target > matrix[i][mid]) {
                    left = mid + 1;
                }
                else if (target < matrix[i][mid]) {
                    right = mid - 1;
                }
                else {
                    return true;
                }
            } 
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_rows = matrix.size(), n_cols = matrix[0].size();
        bool stop = false;

        if (n_rows < 0 || n_rows > 300 || n_cols < 0 || n_cols > 300) {
            return false;
        }

        for (int i = 0; i < n_rows; i++) {
            if (find(matrix, target, i, stop) == true) {
                return true;
            }
            else if (stop == true) {
                return false;
            }
        }

        return false;
        
    }
};