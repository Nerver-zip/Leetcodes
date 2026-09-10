class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        // Ordenar por endDay
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        // Pré-processar endDays para busca binária
        vector<int> endDays(n);
        for (int i = 0; i < n; ++i)
            endDays[i] = events[i][1];

        // dp[i] = melhor valor usando até k eventos, até o evento i
        vector<int> dp(n, 0);

        // Inicialização para k = 1
        dp[0] = events[0][2];
        for (int i = 1; i < n; ++i)
            dp[i] = max(dp[i - 1], events[i][2]);

        // Para k = 2 até k
        for (int kk = 2; kk <= k; ++kk) {
            vector<int> new_dp(n, 0);
            for (int i = 0; i < n; ++i) {
                int include = events[i][2];

                // Busca binária: último j com endDay < startDay[i]
                int lo = 0, hi = i - 1, j = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (endDays[mid] < events[i][0]) {
                        j = mid;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }

                if (j != -1) {
                    include += dp[j]; // valor do nível anterior
                }

                // Skip: new_dp[i-1] | Take: include
                new_dp[i] = max(i > 0 ? new_dp[i - 1] : 0, include);
            }
            dp = new_dp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
