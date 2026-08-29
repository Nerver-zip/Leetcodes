class Solution {
public:
    bool containsCycle(vector<vector<char>>& g) {
        grid = g;
        ROWS = grid.size();
        COLS = grid[0].size();

        visited.assign(ROWS * COLS, 0);

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (!visited[cellIndex(i, j)]) {
                    if (dfs(i, j, -1, -1))
                        return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(int r, int c, int pr, int pc) {
        visited[cellIndex(r, c)] = 1;

        for (int i = 0; i < 4; ++i) {
            int nr = r + directions[i].first;
            int nc = c + directions[i].second;

            if (isOutOfBounds(nr, nc))
                continue;

            if (grid[nr][nc] != grid[r][c])
                continue;

            // não visitado
            if (!visited[cellIndex(nr, nc)]) {
                if (dfs(nr, nc, r, c))
                    return true;
            }
            // visitado e não é o pai → ciclo
            else if (nr != pr || nc != pc) {
                return true;
            }
        }
        return false;
    }

    int ROWS;
    int COLS;

    vector<vector<char>> grid;
    vector<int> visited;

    static constexpr array<pair<int,int>, 4> directions = {{
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    }};

    bool inline isOutOfBounds(int r, int c) {
        return r < 0 || c < 0 || r == ROWS || c == COLS;
    }

    int inline cellIndex(int r, int c) const noexcept {
        return COLS * r + c;
    }
};