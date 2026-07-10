#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
            return 1;

        if (grid[r][c] == 2)
            return 0;

        grid[r][c] = 2;

        return dfs(grid, r - 1, c) +
               dfs(grid, r + 1, c) +
               dfs(grid, r, c - 1) +
               dfs(grid, r, c + 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    return dfs(grid, i, j);
            }
        }

        return 0;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    cout << obj.islandPerimeter(grid) << endl;

    return 0;
}