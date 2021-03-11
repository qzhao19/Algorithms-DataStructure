class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int row) {
        int n_cities = isConnected.size();
        for (int col = 0; col < n_cities; col++) {
            if (visited[col] == false && isConnected[row][col] == 1) {
                visited[col] = true;
                dfs(isConnected, visited, col);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n_cities = isConnected.size();

        vector<bool> visited(n_cities, false);
        int n_circles = 0;

        for (int i = 0; i < n_cities; i++) {
            if (visited[i] == false) {
                dfs(isConnected, visited, i);
                n_circles++;
            }
        }

        return n_circles;
    }
};