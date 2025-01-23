// TC: O(m * n) where m & n are the dimension of the grid
// MC: O(m * n) -> the size of the queue

class Solution {
private:
    int m, n;
    bool isValid(int i, int j, vector<vector<int>>& rooms) {
        return i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] != -1;
    }

    vector<int> dirx = { -1,  0, +1, 0 };
    vector<int> diry = {  0, +1,  0, -1 };

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> Q;
        m = rooms.size(); 
        n = rooms[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    Q.push({i, j});
                }
            }
        }

        while (!Q.empty()) {
            auto u = Q.front();
            Q.pop();

            for (int i = 0; i < 4; ++i) {
                int x = u.first  + dirx[i];
                int y = u.second + diry[i];

                if (isValid(x, y, rooms) && rooms[x][y] == 2147483647) {
                    rooms[x][y] = rooms[u.first][u.second] + 1;
                    Q.push({x, y});
                }
            }
        }
    }
};
