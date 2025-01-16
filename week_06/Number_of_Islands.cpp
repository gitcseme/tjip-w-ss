// TC: O(m * n) where m & n are the dimension of the grid
// SC: O(m * n) recursive stack space for dfs

class Solution {
private:
    vector<int> dirx = { -1,  0, +1,  0 };
    vector<int> diry = {  0, +1,  0, -1 };
    int m, n;

    bool isValid(vector<vector<char>>& grid, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirx[i];
            int ny = y + diry[i];

            if (isValid(grid, nx, ny) && grid[nx][ny] == '1') {
                dfs(grid, nx, ny);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int noOfIsland = 0;
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++noOfIsland;
                    dfs(grid, i, j);
                }
            }
        }

        return noOfIsland;
    }
};
