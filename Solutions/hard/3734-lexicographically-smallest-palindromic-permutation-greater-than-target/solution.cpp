class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        int cnt[26] = {};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Verifica se existe alguma permutação palindrômica.
        int odd = 0;
        int middle = -1;

        for (int c = 0; c < 26; c++) {
            if (cnt[c] % 2) {
                odd++;
                middle = c;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Agora cnt representa apenas as letras da metade esquerda.
        for (int c = 0; c < 26; c++) {
            cnt[c] /= 2;
        }

        auto makePalindrome = [&](const string& left) {
            string ans = left;

            if (middle != -1) {
                ans += char('a' + middle);
            }

            for (int i = (int)left.size() - 1; i >= 0; i--) {
                ans += left[i];
            }

            return ans;
        };

        string left;
        int pos = 0;

        // Tenta ficar exatamente igual ao prefixo de target.
        while (pos < m) {
            int c = target[pos] - 'a';

            if (cnt[c] == 0) {
                break;
            }

            left += target[pos];
            cnt[c]--;
            pos++;
        }

        // Conseguimos copiar toda a metade.
        // Talvez o centro/direita já torne o palíndromo > target.
        if (pos == m) {
            string candidate = makePalindrome(left);

            if (candidate > target) {
                return candidate;
            }
        }

        // Procura o menor "incremento" possível.
        while (true) {

            // Mantém tudo antes de pos igual ao target
            // e tenta colocar a menor letra > target[pos].
            if (pos < m) {
                int current = target[pos] - 'a';

                for (int c = current + 1; c < 26; c++) {
                    if (cnt[c] == 0) {
                        continue;
                    }

                    string nextLeft = left;

                    nextLeft += char('a' + c);
                    cnt[c]--;

                    // Depois do primeiro caractere maior,
                    // basta minimizar o restante.
                    for (int x = 0; x < 26; x++) {
                        nextLeft.append(cnt[x], char('a' + x));
                    }

                    return makePalindrome(nextLeft);
                }
            }

            // Não conseguimos aumentar nesta posição.
            // Precisamos voltar uma posição.
            if (pos == 0) {
                return "";
            }

            pos--;

            int restored = target[pos] - 'a';
            cnt[restored]++;

            left.pop_back();
        }
    }
};