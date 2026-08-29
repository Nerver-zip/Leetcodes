class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> memo;

    int dp(int i, int M) {
        if (i >= n) return 0;

        // Se posso pegar todas as pilhas restantes
        if (i + 2 * M >= n) {
            return suffix[i];
        }

        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int best = 0;

        for (int x = 1; x <= 2 * M; x++) {
            int opponent = dp(i + x, max(M, x));

            int current = suffix[i] - opponent;

            best = max(best, current);
        }

        return memo[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        memo.assign(n, vector<int>(n + 1, -1));

        return dp(0, 1);
    }
};