class Solution {
public:
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int idx, long long val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        long long sum(int idx) {
            long long res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        // Coordinate compression
        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto getId = [&](int x) {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        };

        Fenwick fw(vals.size());

        long long ans = 0;

        for (int x : pref) {
            int id = getId(x);

            // conta quantos prefix anteriores são menores
            ans += fw.sum(id - 1);

            fw.add(id, 1);
        }

        return ans;
    }
};