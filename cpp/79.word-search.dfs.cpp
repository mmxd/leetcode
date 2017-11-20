class Solution {
private:
    bool existHelper(vector<vector<char>> &board, vector<vector<bool>> &visited, string &word, int idx, int i, int j) {
        if (idx == word.size()) {
            return true;
        }

        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int di = i + dir[k][0];
            int dj = j + dir[k][1];

            if (di < 0 || board.size() <= di || dj < 0 || board[0].size() <= dj || visited[di][dj] || board[di][dj] != word[idx]) {
                continue;
            }

            if (existHelper(board, visited, word, idx + 1, di, dj)) {
                return true;
            }
        }

        visited[i][j] = false;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) {
            return true;
        } else if (board.size() == 0 || board[0].size() == 0) {
            return false;
        }

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] &&
                        existHelper(board, visited, word, 1, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
