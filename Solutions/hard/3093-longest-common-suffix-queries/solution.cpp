class Solution {
public:
    using ull = unsigned long long;
    using u128 = __uint128_t;

    // =====================================================
    // Rolling Hash 2^61-1
    // =====================================================

    static constexpr ull MOD = (1ULL << 61) - 1;
    static constexpr ull BASE = 911382323ull;

    static ull modmul(ull a, ull b) {
        u128 t = (u128)a * b;

        ull low = (ull)t & MOD;
        ull high = (ull)(t >> 61);

        ull res = low + high;

        if (res >= MOD)
            res -= MOD;

        return res;
    }

    static ull modadd(ull a, ull b) {
        ull res = a + b;

        if (res >= MOD)
            res -= MOD;

        return res;
    }

    // =====================================================
    // Main
    // =====================================================

    vector<int> stringIndices(
        vector<string>& wordsContainer,
        vector<string>& wordsQuery
    ) {
        // hash(prefix reversed) -> best index
        unordered_map<ull, int> best;

        int globalBest = 0;

        // menor string global
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].size() <
                wordsContainer[globalBest].size()) {
                globalBest = i;
            }
        }

        // preprocess container

        for (int i = 0; i < wordsContainer.size(); ++i) {
            string s = wordsContainer[i];

            reverse(s.begin(), s.end());

            ull h = 0;

            for (char c : s) {
                h = modadd(
                    modmul(h, BASE),
                    (ull)c + 1
                );

                if (!best.count(h)) {
                    best[h] = i;
                }
                else {
                    int j = best[h];

                    // mantém menor tamanho
                    // empate -> menor índice
                    if (wordsContainer[i].size() <
                        wordsContainer[j].size()) {

                        best[h] = i;
                    }
                }
            }
        }

        vector<int> ans;

        for (string q : wordsQuery) {
            reverse(q.begin(), q.end());

            ull h = 0;

            int curBest = globalBest;

            for (char c : q) {
                h = modadd(
                    modmul(h, BASE),
                    (ull)c + 1
                );

                if (!best.count(h))
                    break;

                curBest = best[h];
            }

            ans.push_back(curBest);
        }

        return ans;
    }
};