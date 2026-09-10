class Solution {
public:
    struct SparseTable {
        vector<vector<int>> mx, mn;
        vector<int> lg;

        SparseTable(const vector<int>& nums) {
            int n = nums.size();

            lg.resize(n + 1);
            lg[1] = 0;
            for (int i = 2; i <= n; i++)
                lg[i] = lg[i / 2] + 1;

            int K = lg[n] + 1;

            mx.assign(K, vector<int>(n));
            mn.assign(K, vector<int>(n));

            for (int i = 0; i < n; i++) {
                mx[0][i] = nums[i];
                mn[0][i] = nums[i];
            }

            for (int k = 1; k < K; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    mx[k][i] = max(
                        mx[k - 1][i],
                        mx[k - 1][i + (1 << (k - 1))]
                    );

                    mn[k][i] = min(
                        mn[k - 1][i],
                        mn[k - 1][i + (1 << (k - 1))]
                    );
                }
            }
        }

        long long value(int l, int r) {
            int len = r - l + 1;
            int k = lg[len];

            int maximum = max(
                mx[k][l],
                mx[k][r - (1 << k) + 1]
            );

            int minimum = min(
                mn[k][l],
                mn[k][r - (1 << k) + 1]
            );

            return 1LL * maximum - minimum;
        }
    };

    struct Node {
        long long val;
        int l;
        int r;

        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SparseTable st(nums);

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({
                st.value(l, n - 1),
                l,
                n - 1
            });
        }

        long long ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({
                    st.value(l, r - 1),
                    l,
                    r - 1
                });
            }
        }

        return ans;
    }
};