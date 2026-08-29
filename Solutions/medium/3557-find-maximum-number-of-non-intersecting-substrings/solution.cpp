class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<pair<int,int>> intervals;

        // Para cada índice i, achar o menor j > i com word[j] == word[i] e j - i + 1 >= 4
        for (int i = 0; i < n; ++i) {
            // Vamos buscar o primeiro j >= i+3 (para tamanho >=4) que tenha word[j] == word[i]
            int start = i;
            int minEnd = -1;

            for (int j = i + 3; j < n; ++j) {
                if (word[j] == word[i]) {
                    minEnd = j;
                    break;
                }
            }

            if (minEnd != -1) {
                intervals.emplace_back(start, minEnd);
            }
        }

        // Ordena os intervalos pelo fim (second)
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Contar máximo número de intervalos não sobrepostos
        int count = 0;
        int lastEnd = -1;
        for (auto &[start, end] : intervals) {
            if (start > lastEnd) {
                count++;
                lastEnd = end;
            }
        }

        return count;
    }
};