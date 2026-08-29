class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        // direções
        vector<pair<int,int>> dirs = {{1,1},{1,-1},{-1,-1},{-1,1}};

        auto expected = [&](int k)->int {
            if (k == 0) return 1;
            return (k % 2 ? 2 : 0);
        };

        static int dp0[505][505][4]; // sem virada (t=0)
        static int dp1[505][505][4]; // com virada  (t=1)
        memset(dp0, 0, sizeof(dp0));
        memset(dp1, 0, sizeof(dp1));

        int best = 0;

        // Helper: process all diagonais na direção (dr,dc)
        // startPositions: todos (r,c) tais que a célula anterior (r-dr,c-dc) está fora dos limites.
        auto process_dp0_for_dir = [&](int d){
            int dr = dirs[d].first, dc = dirs[d].second;
            // encontrar starts
            vector<pair<int,int>> starts;
            for (int r = 0; r < n; ++r)
                for (int c = 0; c < m; ++c) {
                    int pr = r - dr, pc = c - dc;
                    if (pr < 0 || pr >= n || pc < 0 || pc >= m)
                        starts.emplace_back(r,c);
                }
            // para cada diagonal comece em start e percorra
            for (auto st : starts) {
                int r = st.first, c = st.second;
                while (r >= 0 && r < n && c >= 0 && c < m) {
                    if (grid[r][c] == 1) {
                        dp0[r][c][d] = max(dp0[r][c][d], 1);
                        best = max(best, dp0[r][c][d]);
                    }
                    int pr = r - dr, pc = c - dc;
                    if (pr >= 0 && pr < n && pc >= 0 && pc < m) {
                        int len = dp0[pr][pc][d];
                        if (len > 0 && grid[r][c] == expected(len)) {
                            dp0[r][c][d] = max(dp0[r][c][d], len + 1);
                            best = max(best, dp0[r][c][d]);
                        }
                    }
                    r += dr; c += dc;
                }
            }
        };

        // Preencher dp0 (sem virada) para todas as 4 direções
        for (int d = 0; d < 4; ++d) process_dp0_for_dir(d);

        // Agora preencher dp1 (com virada)
        auto process_dp1_for_dir = [&](int d){
            int dr = dirs[d].first, dc = dirs[d].second;
            vector<pair<int,int>> starts;
            for (int r = 0; r < n; ++r)
                for (int c = 0; c < m; ++c) {
                    int pr = r - dr, pc = c - dc;
                    if (pr < 0 || pr >= n || pc < 0 || pc >= m)
                        starts.emplace_back(r,c);
                }

            for (auto st : starts) {
                int r = st.first, c = st.second;
                while (r >= 0 && r < n && c >= 0 && c < m) {
                    int pr = r - dr, pc = c - dc;

                    int best_here = dp1[r][c][d]; // já pode ter sido preenchido por outro caminho (inicialmente 0)

                    // 1) continuar após já ter usado a virada (dp1 precedente na mesma direção)
                    if (pr >= 0 && pr < n && pc >= 0 && pc < m) {
                        int len1 = dp1[pr][pc][d];
                        if (len1 > 0 && grid[r][c] == expected(len1)) {
                            best_here = max(best_here, len1 + 1);
                        }
                    }

                    // 2) virar AGORA vindo da direção anterior (sem ter usado virada até aqui)
                    if (pr >= 0 && pr < n && pc >= 0 && pc < m) {
                        int prev = (d + 3) % 4; // direção anterior (counter-clockwise index)
                        int len0 = dp0[pr][pc][prev];
                        if (len0 > 0 && grid[r][c] == expected(len0)) {
                            best_here = max(best_here, len0 + 1);
                        }
                    }

                    dp1[r][c][d] = best_here;
                    best = max(best, dp1[r][c][d]);

                    r += dr; c += dc;
                }
            }
        };

        for (int d = 0; d < 4; ++d) process_dp1_for_dir(d);

        return best;
    }
};