class Solution {
private:
    void numIslandsHelper(const vector<vector<char>> &grid, int m, int n, int i, int j, vector<vector<bool>> &visited) {
        int dir[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
        int di = 0;
        int dj = 0;

        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            di = i + dir[k][0];
            dj = j + dir[k][1];

            if (di < 0 || m <= di || dj < 0 || n <= dj || grid[di][dj] == '0' || visited[di][dj]) {
                continue;
            }

            numIslandsHelper(grid, m, n, di, dj, visited);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    numIslandsHelper(grid, m, n, i, j, visited);
                    ans++;
                }
            }
        }

        return ans;
    }
};
