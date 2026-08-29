class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modexp(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        map<pair<int,int>, vector<tuple<int,int,int>>> groups;

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k <= B) {
                groups[{k, l % k}].push_back({l, r, v});
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1LL * nums[i] * v % MOD;
                }
            }
        }

        for (auto &[key, vec] : groups) {
            auto [k, rem] = key;

            vector<int> idx;
            for (int i = rem; i < n; i += k)
                idx.push_back(i);

            int m = idx.size();
            vector<long long> diff(m + 1, 1);

            for (auto &[l, r, v] : vec) {
                int L = (l - rem + k - 1) / k;
                int R = (r - rem) / k;

                if (L <= R) {
                    diff[L] = diff[L] * v % MOD;
                    diff[R + 1] = diff[R + 1] * modexp(v, MOD - 2) % MOD;
                }
            }

            long long cur = 1;
            for (int i = 0; i < m; i++) {
                cur = cur * diff[i] % MOD;
                nums[idx[i]] = nums[idx[i]] * cur % MOD;
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};