class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    long long modPow(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp & 1)
                result = result * base % MOD;

            base = base * base % MOD;
            exp >>= 1;
        }

        return result;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        vector<long long> fact(N + 1);
        fact[0] = 1;

        for (int i = 1; i <= N; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        long long denominator =
            fact[R] * fact[N - R] % MOD;

        long long ans =
            fact[N] * modPow(denominator, MOD - 2) % MOD;

        return ans;
    }
};