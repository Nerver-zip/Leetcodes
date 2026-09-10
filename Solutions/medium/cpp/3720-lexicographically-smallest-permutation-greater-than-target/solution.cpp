class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        array<int, 26> freq{};
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans;
        ans.reserve(n);

        // Tenta copiar o maior prefixo possível de target.
        int i = 0;
        while (i < n) {
            int x = target[i] - 'a';

            if (freq[x] > 0) {
                ans.push_back(target[i]);
                freq[x]--;
                i++;
            } else {
                break;
            }
        }

        // Função que tenta "aumentar" a posição i:
        // escolhe a menor letra disponível > target[i]
        // e completa o sufixo da menor forma possível.
        auto tryFinish = [&](int pos) -> bool {
            int cur = target[pos] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (freq[c] == 0) continue;

                ans.push_back(char('a' + c));
                freq[c]--;

                for (int d = 0; d < 26; d++) {
                    while (freq[d] > 0) {
                        ans.push_back(char('a' + d));
                        freq[d]--;
                    }
                }

                return true;
            }

            return false;
        };

        // Caso 1:
        // travamos antes de copiar target inteiro.
        if (i < n) {
            if (tryFinish(i)) {
                return ans;
            }
        }

        // Caso 2:
        // ou não havia letra maior nessa posição,
        // ou conseguimos formar target inteiro (ans == target).
        // Backtrack da direita para a esquerda.
        for (int pos = i - 1; pos >= 0; pos--) {
            char removed = ans.back();
            ans.pop_back();
            freq[removed - 'a']++;

            if (tryFinish(pos)) {
                return ans;
            }
        }

        return "";
    }
};