constexpr int MOD = 1000000007; 
using ll = long long;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<ll> pow10(n + 1, 1);
        
        // cnt[i] = quantidade de dígitos não-zero em s[0..i-1]
        // sum[i] = soma dos dígitos em s[0..i-1]
        // val[i] = número formado concatenando os não-zeros de s[0..i-1], mod MOD
        vector<ll> val(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<ll> sum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pow10[i + 1] = pow10[i] * 10 % MOD;

            int d = s[i] - '0';

            cnt[i + 1] = cnt[i];
            sum[i + 1] = sum[i] + d;
            val[i + 1] = val[i];

            if (d != 0) {
                cnt[i + 1]++;
                val[i + 1] = (val[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int k = cnt[r + 1] - cnt[l];

            ll x = (val[r + 1] - val[l] * pow10[k]) % MOD;
            if (x < 0) x += MOD;

            ll digitSum = sum[r + 1] - sum[l];

            ans.push_back(x * digitSum % MOD);
        }

        return ans;
    }
};