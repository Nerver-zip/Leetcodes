class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Remove moedas redundantes.
        // Se temos 3 e 6, a moeda 6 não adiciona nenhum valor novo,
        // pois todo múltiplo de 6 já é múltiplo de 3.
        sort(coins.begin(), coins.end());

        vector<long long> c;

        for (int coin : coins) {
            bool redundant = false;

            for (long long x : c) {
                if (coin % x == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant) {
                c.push_back(coin);
            }
        }

        int n = c.size();

        // Pré-calcula o LCM e o sinal de cada subconjunto.
        vector<pair<long long, int>> subsets;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long lcm = 1;
            int bits = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    ++bits;

                    long long g = gcd(lcm, c[i]);
                    lcm = lcm / g * c[i];
                }
            }

            // tamanho ímpar -> +1
            // tamanho par   -> -1
            int sign = (bits % 2 == 1 ? 1 : -1);

            subsets.push_back({lcm, sign});
        }

        auto count = [&](long long x) {
            long long total = 0;

            for (auto [lcm, sign] : subsets) {
                total += sign * (x / lcm);
            }

            return total;
        };

        // minCoin * k sempre é um limite superior:
        // usando apenas a menor moeda, já existem k valores.
        long long left = 1;
        long long right = c[0] * (long long) k;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};