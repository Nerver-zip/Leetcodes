using ll = long long;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        // Prefix do lucro original: strategy[i] * prices[i]
        vector<long long> prefProfit(n + 1, 0);
        // Prefix dos preços
        vector<long long> prefPrice(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefProfit[i + 1] = prefProfit[i] + 1LL * strategy[i] * prices[i];
            prefPrice[i + 1]  = prefPrice[i]  + prices[i];
        }

        long long baseProfit = prefProfit[n];
        long long maxGain = 0;

        // Testa todas as janelas de tamanho k
        for (int l = 0; l + k <= n; l++) {
            int r = l + k;

            // Lucro original da janela [l, r)
            long long oldProfit =
                prefProfit[r] - prefProfit[l];

            // Novo lucro da janela:
            // primeira metade -> 0
            // segunda metade  -> 1
            long long newProfit =
                prefPrice[r] - prefPrice[l + k / 2];

            long long gain = newProfit - oldProfit;
            maxGain = max(maxGain, gain);
        }

        return baseProfit + maxGain;
    }
};
