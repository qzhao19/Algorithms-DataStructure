class Solution {
public:
    bool checkSmallerValue(vector<vector<int>> &matrix, int mid, int k, int n) {
        int i = n - 1, j = 0;
        int cnt = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                cnt += i + 1;
                j++;
            } 
            else {
                i--;
            }
        }

        return cnt >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n < 0 || n > 300) {
            return 0;
        }

        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        int mid;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (checkSmallerValue(matrix, mid, k, n)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};