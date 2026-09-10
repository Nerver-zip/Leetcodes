class Solution {
    using ll = long long;

    struct Node {
        ll cnt;
        ll sum;
    };

    string s;
    Node memo[20][3][11][11];
    bool vis[20][3][11][11];

    Node dfs(int pos, bool tight, int len, int last2, int last1) {
        if (pos == (int)s.size())
            return {1, 0};

        if (!tight && vis[pos][len][last2][last1])
            return memo[pos][len][last2][last1];

        int lim = tight ? s[pos] - '0' : 9;

        Node ans{0, 0};

        for (int d = 0; d <= lim; d++) {
            bool ntight = tight && (d == lim);

            Node cur;

            if (len == 0) {
                if (d == 0) {
                    cur = dfs(pos + 1, ntight, 0, 10, 10);
                } else {
                    cur = dfs(pos + 1, ntight, 1, 10, d);
                }
            }
            else if (len == 1) {
                cur = dfs(pos + 1, ntight, 2, last1, d);
            }
            else {
                int add =
                    ((last1 > last2 && last1 > d) ||
                     (last1 < last2 && last1 < d));

                cur = dfs(pos + 1, ntight, 2, last1, d);

                cur.sum += cur.cnt * add;
            }

            ans.cnt += cur.cnt;
            ans.sum += cur.sum;
        }

        if (!tight) {
            vis[pos][len][last2][last1] = true;
            memo[pos][len][last2][last1] = ans;
        }

        return ans;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, 10, 10).sum;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};