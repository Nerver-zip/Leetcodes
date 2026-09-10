class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void init(int n) {
        fact.resize(n+1);
        invFact.resize(n+1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i-1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD-2);
        for (int i = n-1; i >= 0; i--)
            invFact[i] = invFact[i+1] * (i+1) % MOD;
    }

    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n-k] % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        init(n);
        return nCk(n-1, k) * 2 % MOD;
    }
};