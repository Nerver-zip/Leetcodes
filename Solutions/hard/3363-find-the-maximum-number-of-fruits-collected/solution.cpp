class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& a) {
        int n = a.size();
        int total = 0;

        // Soma diagonal principal da matriz original
        for (int i = 0; i < n; ++i) {
            total += a[i][i];
        }

        // Copia a matriz e zera diagonal principal
        vector<vector<int>> fruits = a;
        for (int i = 0; i < n; ++i) {
            fruits[i][i] = 0;
        }

        // DP Criança Vermelha (top-right)
        vector<vector<int>> red(n, vector<int>(n, -1));
        red[0][n - 1] = fruits[0][n - 1];

        for (int i = 1; i < n; ++i) {
            for (int j = n - 1; j > i; --j) { // j > i para não tocar diagonal
                int best = -1;
                for (int dj = -1; dj <= 1; ++dj) {
                    int prev_j = j + dj;
                    if (prev_j >= 0 && prev_j < n && prev_j > i - 1 && red[i - 1][prev_j] != -1) {
                        best = max(best, red[i - 1][prev_j]);
                    }
                }
                if (best != -1)
                    red[i][j] = best + fruits[i][j];
            }
        }

        // DP Criança Azul (bottom-left)
        vector<vector<int>> blue(n, vector<int>(n, -1));
        blue[n - 1][0] = fruits[n - 1][0];

        for (int j = 1; j < n; ++j) {
            for (int i = n - 1; i > j; --i) { // i > j para não tocar diagonal
                int best = -1;
                for (int di = -1; di <= 1; ++di) {
                    int prev_i = i + di;
                    if (prev_i >= 0 && prev_i < n && prev_i > j - 1 && blue[prev_i][j - 1] != -1) {
                        best = max(best, blue[prev_i][j - 1]);
                    }
                }
                if (best != -1)
                    blue[i][j] = best + fruits[i][j];
            }
        }

        int best_red = 0, best_blue = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (red[i][j] != -1)
                    best_red = max(best_red, red[i][j]);
                if (blue[j][i] != -1)
                    best_blue = max(best_blue, blue[j][i]);
            }
        }

        return total + best_red + best_blue;
    }
};