class Solution {
    struct Interval {
        int l, r, w, idx;
    };

    struct State {
        long long score = 0;
        vector<int> ids;
    };

    State best(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;

        return a.ids < b.ids ? a : b;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<Interval> a;
        a.reserve(n);

        for (int i = 0; i < n; ++i) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Hint 2: ordenar pelo right boundary
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x.r != y.r)
                return x.r < y.r;
            return x.l < y.l;
        });

        vector<int> rights(n);

        for (int i = 0; i < n; ++i)
            rights[i] = a[i].r;

        // prev[i] = quantidade de intervalos no prefixo
        // cujo right < a[i].left
        vector<int> prev(n);

        for (int i = 0; i < n; ++i) {
            prev[i] = lower_bound(
                rights.begin(),
                rights.end(),
                a[i].l
            ) - rights.begin();
        }

        /*
            dp[k][i]:

            melhor solução escolhendo NO MÁXIMO k intervalos
            entre os primeiros i intervalos.

            i = 0 significa prefixo vazio.
        */
        vector<vector<State>> dp(5, vector<State>(n + 1));

        for (int k = 1; k <= 4; ++k) {
            for (int i = 1; i <= n; ++i) {

                // intervalo atual é a[i - 1]
                auto& cur = a[i - 1];

                // 1. Não pegar o intervalo atual
                State skip = dp[k][i - 1];

                // 2. Pegar o intervalo atual
                //
                // prev[i-1] = número de intervalos que terminam
                // antes de cur começar.
                State take = dp[k - 1][prev[i - 1]];

                take.score += cur.w;
                take.ids.push_back(cur.idx);

                // Precisamos comparar lexicograficamente pelos
                // índices ORIGINAIS.
                sort(take.ids.begin(), take.ids.end());

                dp[k][i] = best(skip, take);
            }
        }

        return dp[4][n].ids;
    }
};