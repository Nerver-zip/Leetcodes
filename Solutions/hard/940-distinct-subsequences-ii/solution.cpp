class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> dp(n + 1);
        vector<int> last(26, 0);

        dp[0] = 1; // subsequência vazia

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];

            dp[i] = (2 * dp[i - 1]) % MOD;

            int prev = last[c - 'a'];

            if (prev != 0) {
                dp[i] = (dp[i] - dp[prev - 1] + MOD) % MOD;
            }

            last[c - 'a'] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};