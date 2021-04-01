#include<iostream>
#include<vector>
using namespace std;

int n_rows, n_cols;
vector<vector<int>> maze;
vector<vector<int>> path;
vector<vector<int>> result;

void backtrack(int x, int y) {
    int tmp = maze[x][y];
    maze[x][y] = 1;
    path.push_back({x, y});

    if ((x == n_rows - 1) && (y == n_cols - 1)) {
        if (result.empty() || path.size() < result.size()) {
            result = path;
        }
        return ;
    }
    
    if ((x - 1 >= 0) && maze[x-1][y] == 0) {
        backtrack(x - 1, y);
    }
    
    if ((x + 1 < n_rows) && (maze[x+1][y] == 0)) {
        backtrack(x + 1, y);
    }
    
    if ((y - 1 >= 0) && maze[x][y-1] == 0) {
        backtrack(x, y - 1);
    }
    
    if ((y + 1 < n_cols) && (maze[x][y+1] == 0)) {
        backtrack(x, y + 1);
    }
    
    maze[x][y] = tmp;
    
}

int main() {
    while (cin >> n_rows >> n_cols) {
        maze = vector<vector<int>>(n_rows, vector<int>(n_cols, 0));
        path.clear();
        result.clear();
        
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                cin >> maze[i][j];
            }
        }
        
        backtrack(0, 0);
        for (auto res : result) {
            cout << '(' << res[0] << ',' << res[1] << ')' << endl;
        }
    }
    
    return 0;
}





















