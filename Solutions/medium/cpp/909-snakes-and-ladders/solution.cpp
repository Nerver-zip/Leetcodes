class Solution {
private:
    pair<int, int> getCoordinates(int num, int n) {
        int r = n - 1 - (num - 1) / n;
        int c = (num - 1) % n;
        if (((n - 1 - r) % 2) == 1) {
            c = n - 1 - c;
        }
        return {r, c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // {current_square, moves}
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n) continue;

                auto [row, col] = getCoordinates(next, n);
                if (board[row][col] != -1) {
                    next = board[row][col];
                }

                if (next == n * n) {
                    return moves + 1;
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};