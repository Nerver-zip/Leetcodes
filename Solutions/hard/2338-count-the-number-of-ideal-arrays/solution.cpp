typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
public:
    vector<ll> fact, invFact;

    ll modPow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void initFactorials(int n) {
        fact.assign(n + 1, 1);
        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    ll comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        int maxLen = 14; // suficiente (log2(1e4) ~= 14)
        initFactorials(n + maxLen + 1);

        vector<vector<ll>> dp(maxValue + 1, vector<ll>(maxLen + 1, 0));
        for (int i = 1; i <= maxValue; ++i)
            dp[i][1] = 1;

        for (int len = 2; len <= maxLen; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int k = 2 * i; k <= maxValue; k += i) {
                    dp[k][len] = (dp[k][len] + dp[i][len - 1]) % MOD;
                }
            }
        }

        ll ans = 0;
        for (int len = 1; len <= maxLen; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                if (dp[i][len] == 0) continue;
                ans = (ans + dp[i][len] * comb(n - 1, len - 1) % MOD) % MOD;
            }
        }
        return (int)ans;
    }
};
