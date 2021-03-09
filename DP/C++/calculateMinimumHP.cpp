class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int n_rows = dungeon.size(), n_cols = dungeon[0].size();

        vector<vector<int>> d(n_rows, vector<int>(n_cols, INT_MAX));

        for(int i = n_rows - 1; i >= 0; --i){
            for(int j = n_cols - 1; j >= 0;--j){
                if(i == n_rows - 1 && j == n_cols - 1){
                    d[i][j] = max(1, 1 - dungeon[i][j]);
                }else if(j == n_cols - 1){
                    d[i][j] = max(1,d[i+1][j] - dungeon[i][j]);
                }else if(i == n_rows - 1){
                    d[i][j] = max(1, d[i][j+1] - dungeon[i][j]);
                }else{
                    d[i][j] = max(1,min(d[i+1][j], d[i][j+1]) - dungeon[i][j]);
                }
            }
        }
        return d[0][0];
    }
};