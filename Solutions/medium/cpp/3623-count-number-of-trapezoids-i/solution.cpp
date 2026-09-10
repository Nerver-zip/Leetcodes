class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    long long countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> freq; 
        freq.reserve(points.size() * 2);

        // Conta quantos pontos existem em cada y
        for (auto &p : points)
            freq[p[1]]++;

        long long sumS = 0;    // soma dos S_y
        long long sumSq = 0;   // soma de S_y^2

        for (auto &[y, k] : freq) {
            if (k >= 2) {
                long long S = (1LL * k * (k - 1) / 2) % MOD;
                sumS = (sumS + S) % MOD;
                sumSq = (sumSq + (S * S) % MOD) % MOD;
            }
        }

        // Fórmula final:
        // resposta = (sumS^2 - sumSq) / 2
        long long total = (sumS * sumS) % MOD;
        total = (total - sumSq + MOD) % MOD;

        // multiplicar por inverso modular de 2 (500000004)
        total = (total * 500000004LL) % MOD;

        return total;
    }
};
