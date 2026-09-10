class Solution {
public:
    const int MOD = 1e9 + 7;

    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1) res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return res;
    }

    long long modinv(long long a) {
        return binpow(a, MOD - 2);  // Fermat's little theorem
    }

    vector<long long> fact, invfact;

    void precompute(int n) {
        fact.resize(n + 1);
        invfact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invfact[n] = modinv(fact[n]);
        for (int i = n - 1; i >= 0; --i) invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precompute(n);
        long long ways = comb(n - 1, k);
        long long assign = m * binpow(m - 1, n - k - 1) % MOD;
        return ways * assign % MOD;
    }
};