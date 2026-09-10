class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        
        // Conta a frequência de cada dígito e calcula a soma total
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }

        // Se a soma total não for par, não é possível balancear
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;

        // Inicializa a tabela de combinações (coeficientes binomiais)
        vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1, 0));
        vector<vector<long long>> f(target + 1, vector<long long>(maxOdd + 1, 0));

        // Calcula as combinações
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        // Inicia a DP
        f[0][0] = 1;
        int psum = 0, totSum = 0;

        // Processa os dígitos de 0 a 9
        for (int i = 0; i <= 9; i++) {
            psum += cnt[i];         // Atualiza o número total de elementos processados
            totSum += i * cnt[i];   // Atualiza a soma total dos dígitos

            // Loop que processa a distribuição de dígitos nas posições ímpares e pares
            for (int oddCnt = min(psum, maxOdd); oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--) {
                int evenCnt = psum - oddCnt;

                // Loop para processar as somas
                for (int curr = min(totSum, target); curr >= max(0, totSum - target); curr--) {
                    long long res = 0;

                    // Processa a alocação de dígitos
                    for (int j = max(0, cnt[i] - evenCnt); j <= min(cnt[i], oddCnt) && i * j <= curr; j++) {
                        // Calcula o número de maneiras de distribuir os dígitos nas posições ímpares e pares
                        long long ways = comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                        res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) % MOD;
                    }

                    // Atualiza a tabela de DP
                    f[curr][oddCnt] = res % MOD;
                }
            }
        }

        return f[target][maxOdd];
    }
};