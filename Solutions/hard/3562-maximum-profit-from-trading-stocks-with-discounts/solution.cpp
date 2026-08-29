class Solution {
public:
    int maxProfit(int n,
                  vector<int>& present,
                  vector<int>& future,
                  vector<vector<int>>& hierarchy,
                  int budget) {

        vector<vector<int>> g(n);
        for (auto& e : hierarchy) {
            g[e[0] - 1].push_back(e[1] - 1);
        }

        // dfs retorna:
        // dp0[b] -> lucro máximo com custo b, se o pai NÃO comprou
        // dp1[b] -> lucro máximo com custo b, se o pai COMPROU
        // sz     -> custo máximo possível da subárvore
        auto dfs = [&](auto&& self, int u)
            -> tuple<vector<int>, vector<int>, int> {

            int cost  = present[u];
            int dCost = present[u] / 2;

            vector<int> dp0(budget + 1, 0);
            vector<int> dp1(budget + 1, 0);

            vector<int> sub0(budget + 1, 0); // filhos sem desconto
            vector<int> sub1(budget + 1, 0); // filhos com desconto

            int sz = cost;

            // combina os filhos
            for (int v : g[u]) {
                auto [c0, c1, csz] = self(self, v);
                sz += csz;

                for (int i = budget; i >= 0; i--) {
                    for (int j = 0; j <= min(csz, i); j++) {
                        sub0[i] = max(sub0[i], sub0[i - j] + c0[j]);
                        sub1[i] = max(sub1[i], sub1[i - j] + c1[j]);
                    }
                }
            }

            // caso: NÃO comprar u
            for (int i = 0; i <= budget; i++) {
                dp0[i] = sub0[i];
                dp1[i] = sub0[i];
            }

            // caso: COMPRAR u
            for (int i = 0; i <= budget; i++) {
                if (i >= cost) {
                    dp0[i] = max(dp0[i],
                                 sub1[i - cost] + future[u] - cost);
                }
                if (i >= dCost) {
                    dp1[i] = max(dp1[i],
                                 sub1[i - dCost] + future[u] - dCost);
                }
            }

            return {dp0, dp1, sz};
        };

        auto [dp0, dp1, _] = dfs(dfs, 0);
        return dp0[budget];
    }
};
