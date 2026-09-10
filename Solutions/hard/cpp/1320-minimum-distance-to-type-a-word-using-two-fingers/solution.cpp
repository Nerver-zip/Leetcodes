class Solution {
public:
    int dist(int a, int b) {
        if (a == -1 || b == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        const int INF = 1e9;

        vector<vector<int>> dp(27, vector<int>(27, INF));
        dp[26][26] = 0; // ambos livres (-1)

        for (char c : word) {
            int cur = c - 'A';

            vector<vector<int>> ndp(27, vector<int>(27, INF));

            for (int f1 = 0; f1 <= 26; ++f1) {
                for (int f2 = 0; f2 <= 26; ++f2) {
                    if (dp[f1][f2] == INF) continue;

                    int pos1 = (f1 == 26 ? -1 : f1);
                    int pos2 = (f2 == 26 ? -1 : f2);

                    // usa dedo 1
                    ndp[cur][f2] = min(
                        ndp[cur][f2],
                        dp[f1][f2] + dist(pos1, cur)
                    );

                    // usa dedo 2
                    ndp[f1][cur] = min(
                        ndp[f1][cur],
                        dp[f1][f2] + dist(pos2, cur)
                    );
                }
            }

            dp = ndp;
        }

        int ans = INF;
        for (int i = 0; i <= 26; ++i)
            for (int j = 0; j <= 26; ++j)
                ans = min(ans, dp[i][j]);

        return ans;
    }
};