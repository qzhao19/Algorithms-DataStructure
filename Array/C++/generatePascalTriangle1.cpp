class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows < 1) {
            return {};
        }

        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            triangle.push_back(vector<int>(i + 1, 1));
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};