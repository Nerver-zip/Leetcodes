class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        if (n == 1) return m;

        vector<int> up(m + 1), down(m + 1);
        vector<int> newUp(m + 1), newDown(m + 1);
        vector<int> pref(m + 1);

        // length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {

            // prefix of down
            pref[0] = 0;
            for (int i = 1; i <= m; i++) {
                pref[i] = pref[i - 1] + down[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            for (int v = 1; v <= m; v++) {
                newUp[v] = pref[v - 1];
            }

            // prefix of up
            pref[0] = 0;
            for (int i = 1; i <= m; i++) {
                pref[i] = pref[i - 1] + up[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            int totalUp = pref[m];

            for (int v = 1; v <= m; v++) {
                newDown[v] = totalUp - pref[v];
                if (newDown[v] < 0)
                    newDown[v] += MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        for (int v = 1; v <= m; v++) {
            ans += up[v];
            ans += down[v];
        }

        return ans % MOD;
    }
};