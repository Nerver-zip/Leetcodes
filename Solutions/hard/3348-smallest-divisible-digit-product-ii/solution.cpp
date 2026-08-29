class Solution {
    using A = array<int, 4>;

    // ordem: expoentes de 2, 3, 5, 7
    const int fact[10][4] = {
        {0,0,0,0}, // 0
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    // Converte os fatores que ainda faltam para a menor quantidade
    // possível de dígitos.
    vector<int> getDigits(A need) {
        vector<int> cnt(10);

        // Para potências de 2, usar 8 é mais eficiente.
        cnt[8] = need[0] / 3;
        need[0] %= 3;

        // Para potências de 3, usar 9 é mais eficiente.
        cnt[9] = need[1] / 2;
        need[1] %= 2;

        cnt[4] = need[0] / 2;
        cnt[2] = need[0] % 2;

        cnt[3] = need[1];

        // 2 * 3 -> 6
        if (cnt[2] && cnt[3]) {
            cnt[2]--;
            cnt[3]--;
            cnt[6]++;
        }

        /*
         * 3 * 4 e 2 * 6 possuem o mesmo produto (=12)
         * e a mesma quantidade de dígitos.
         *
         * Mas "26" < "34", então preferimos 2,6.
         */
        if (cnt[3] && cnt[4]) {
            cnt[3]--;
            cnt[4]--;

            cnt[2]++;
            cnt[6]++;
        }

        // Só o dígito 5 possui fator 5.
        cnt[5] = need[2];

        // Só o dígito 7 possui fator 7.
        cnt[7] = need[3];

        return cnt;
    }

    int digitCount(const vector<int>& cnt) {
        int ans = 0;
        for (int d = 2; d <= 9; ++d)
            ans += cnt[d];
        return ans;
    }

    string build(const vector<int>& cnt) {
        string ans;

        // ordem crescente = menor número
        for (int d = 2; d <= 9; ++d) {
            ans += string(cnt[d], char('0' + d));
        }

        return ans;
    }

public:
    string smallestNumber(string num, long long t) {
        A need = {0, 0, 0, 0};

        int primes[4] = {2, 3, 5, 7};

        // 1. Fatora t
        for (int i = 0; i < 4; ++i) {
            while (t % primes[i] == 0) {
                t /= primes[i];
                need[i]++;
            }
        }

        // Existe algum fator primo diferente de 2,3,5,7.
        if (t != 1)
            return "-1";

        int n = num.size();

        /*
         * Número mínimo de dígitos necessários para produzir t.
         */
        vector<int> allDigits = getDigits(need);
        int minRequired = digitCount(allDigits);

        /*
         * Se nem um número de n dígitos consegue ter fatores suficientes,
         * a resposta terá necessariamente mais dígitos.
         */
        if (minRequired > n) {
            return build(allDigits);
        }

        // Fatores fornecidos pelo num inteiro.
        A prefix = {0, 0, 0, 0};

        for (char ch : num) {
            int d = ch - '0';
            for (int j = 0; j < 4; ++j)
                prefix[j] += fact[d][j];
        }

        /*
         * Se existe 0, o próprio num não pode ser resposta.
         *
         * Além disso, se vamos mudar algum dígito, a mudança precisa
         * acontecer no primeiro zero ou antes dele; caso contrário
         * aquele zero continuaria no prefixo.
         */
        int firstZero = n;

        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }

        // O próprio num já serve?
        if (firstZero == n) {
            bool ok = true;

            for (int j = 0; j < 4; ++j) {
                if (prefix[j] < need[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return num;
        }

        /*
         * Tentamos alterar o dígito mais à direita possível.
         *
         * Quanto mais à direita ocorrer a primeira diferença,
         * menor será o resultado.
         */
        for (int i = n - 1; i >= 0; --i) {
            int oldDigit = num[i] - '0';

            // Agora prefix contém somente num[0 ... i-1].
            for (int j = 0; j < 4; ++j)
                prefix[j] -= fact[oldDigit][j];

            /*
             * Se existe um zero antes dessa posição,
             * mudar aqui não resolveria o problema do zero.
             */
            if (i > firstZero)
                continue;

            int available = n - i - 1;

            // Tenta o menor dígito maior que o atual.
            for (int newDigit = oldDigit + 1;
                 newDigit <= 9;
                 ++newDigit) {

                A remaining;

                // Fatores que ainda faltam depois de:
                // prefixo + newDigit
                for (int j = 0; j < 4; ++j) {
                    remaining[j] =
                        max(0,
                            need[j]
                            - prefix[j]
                            - fact[newDigit][j]);
                }

                vector<int> suffixDigits = getDigits(remaining);
                int required = digitCount(suffixDigits);

                if (required > available)
                    continue;

                /*
                 * Encontramos a primeira solução.
                 *
                 * Colocamos 1s antes dos outros dígitos porque 1
                 * não muda o produto e deixa o número menor.
                 */
                string ans = num.substr(0, i);

                ans.push_back(char('0' + newDigit));

                ans += string(available - required, '1');

                ans += build(suffixDigits);

                return ans;
            }
        }

        /*
         * Não existe resposta com n dígitos.
         *
         * Usamos n+1 dígitos.
         * Como qualquer número de n+1 dígitos é > num,
         * basta construir o menor deles.
         */
        allDigits = getDigits(need);
        minRequired = digitCount(allDigits);

        string ans(n + 1 - minRequired, '1');
        ans += build(allDigits);

        return ans;
    }
};