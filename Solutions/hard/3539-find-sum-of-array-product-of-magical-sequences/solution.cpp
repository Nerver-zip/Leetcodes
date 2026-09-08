const int MOD = 1e9 + 7;

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        Comb comb(m);

        // Precompute powers nums[i]^c
        vector<vector<long long>> pows(n, vector<long long>(m+1, 1));
        for (int i = 0; i < n; i++) {
            long long base = nums[i] % MOD;
            for (int c = 1; c <= m; c++) {
                pows[i][c] = pows[i][c-1] * base % MOD;
            }
        }

        // dp[u][p][q]
        vector<vector<vector<long long>>> dp(
            m+1, vector<vector<long long>>(m+1, vector<long long>(k+1, 0))
        );
        dp[0][0][0] = 1;

        for (int idx = 0; idx < n; idx++) {
            auto newdp = vector<vector<vector<long long>>>(
                m+1, vector<vector<long long>>(m+1, vector<long long>(k+1, 0))
            );

            for (int u = 0; u <= m; u++) {
                for (int p = 0; p <= m; p++) {
                    for (int q = 0; q <= k; q++) {
                        long long cur = dp[u][p][q];
                        if (!cur) continue;
                        int rem = m - u;
                        for (int c = 0; c <= rem; c++) {
                            int newu = u + c;
                            int s = p + c;
                            int bit = s & 1;
                            int newp = s >> 1;
                            int newq = q + bit;
                            if (newq > k) continue;

                            long long ways = comb.C(rem, c);
                            long long mult = pows[idx][c];
                            long long add = cur * ways % MOD * mult % MOD;
                            newdp[newu][newp][newq] += add;
                            if (newdp[newu][newp][newq] >= MOD) 
                                newdp[newu][newp][newq] -= MOD;
                        }
                    }
                }
            }

            dp.swap(newdp);
        }
        long long ans = 0;
        for (int p = 0; p <= m; p++) {
            int pc = __builtin_popcount(p);
            for (int q = 0; q <= k; q++) {
                if (q + pc == k) {
                    ans += dp[m][p][q];
                    if (ans >= MOD) ans -= MOD;
                }
            }
        }
        return (int)ans;
    }
private:
    struct Comb {
        vector<long long> fact, invfact;
        int n;
        Comb(int n) : n(n) {
            fact.resize(n+1);
            invfact.resize(n+1);
            fact[0] = 1;
            for (int i = 1; i <= n; i++) 
                fact[i] = fact[i-1] * i % MOD;
            invfact[n] = modpow(fact[n], MOD-2);
            for (int i = n; i >= 1; i--) 
                invfact[i-1] = invfact[i] * i % MOD;
        }
        static long long modpow(long long a, long long e) {
            long long r = 1;
            while (e) {
                if (e & 1) r = r * a % MOD;
                a = a * a % MOD;
                e >>= 1;
            }
            return r;
        }
        long long C(int N, int K) {
            if (K < 0 || K > N) return 0;
            return fact[N] * invfact[K] % MOD * invfact[N-K] % MOD;
        }
    };
};