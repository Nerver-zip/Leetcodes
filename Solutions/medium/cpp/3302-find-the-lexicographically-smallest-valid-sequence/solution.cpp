class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // right[j] = posição mais à direita possível em word1
        // para casar word2[j...] exatamente.
        vector<int> right(m, -1);

        int j = m - 1;

        // Greedy de trás para frente.
        for (int i = n - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                right[j] = i;
                --j;
            }
        }

        vector<int> ans;

        j = 0;
        bool usedMismatch = false;

        // Greedy da esquerda para a direita.
        for (int i = 0; i < n && j < m; ++i) {

            // Melhor caso: match exato.
            // Sempre vale pegar o índice mais cedo possível.
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            }

            // Podemos gastar nossa única diferença aqui?
            else if (!usedMismatch) {

                // Se j for o último caractere, não há sufixo.
                //
                // Caso contrário, right[j + 1] > i significa que
                // word2[j+1...] consegue ser formado exatamente
                // depois da posição i.
                if (j == m - 1 || right[j + 1] > i) {
                    ans.push_back(i);
                    ++j;
                    usedMismatch = true;
                }
            }
        }

        // Não conseguimos selecionar m índices.
        if (j != m)
            return {};

        return ans;
    }
};