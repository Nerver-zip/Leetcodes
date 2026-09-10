class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        // L[i] = índice em t onde s[i] foi casado
        // no matching guloso da esquerda
        vector<int> L(n, -1);

        // R[i] = índice em t onde s[i] foi casado
        // no matching guloso da direita
        vector<int> R(n, -1);

        // Prefix matching
        int j = 0;

        for (int i = 0; i < n && j < m; i++) {
            while (j < m && t[j] != s[i]) {
                j++;
            }

            if (j < m) {
                L[i] = j;
                j++;
            }
        }

        // Suffix matching
        j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) {
                j--;
            }

            if (j >= 0) {
                R[i] = j;
                j--;
            }
        }

        // Caso sem precisar substituir nada
        if (L[n - 1] != -1) {
            return true;
        }

        // Tentamos substituir s[k]
        for (int k = 0; k < n; k++) {
            int left = -1;
            int right = m;

            // Precisamos casar tudo antes de k
            if (k > 0) {
                if (L[k - 1] == -1) {
                    continue;
                }

                left = L[k - 1];
            }

            // Precisamos casar tudo depois de k
            if (k + 1 < n) {
                if (R[k + 1] == -1) {
                    continue;
                }

                right = R[k + 1];
            }

            // Precisa existir um slot entre eles
            if (left < right - 1) {
                return true;
            }
        }

        return false;
    }
};