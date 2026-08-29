class Solution {
private:
    static constexpr long long NEG_INF = LLONG_MIN / 4;

    long long solve(
        int i,
        int t,
        int s,
        int k,
        const vector<int>& prices,
        vector<vector<vector<long long>>>& dp
    ) {
        int n = prices.size();

        if (i == n) {
            return (s == 0 ? 0LL : NEG_INF);
        }

        if (t == k) {
            return (s == 0 ? 0LL : NEG_INF);
        }

        long long& res = dp[i][t][s];
        if (res != LLONG_MIN) return res;

        res = NEG_INF;

        if (s == 0) {
            res = max(res, solve(i + 1, t, 0, k, prices, dp));
            res = max(res, -1LL * prices[i] + solve(i + 1, t, 1, k, prices, dp));
            res = max(res,  1LL * prices[i] + solve(i + 1, t, 2, k, prices, dp));
        }
        else if (s == 1) {
            res = max(res, solve(i + 1, t, 1, k, prices, dp));
            res = max(res, 1LL * prices[i] + solve(i + 1, t + 1, 0, k, prices, dp));
        }
        else {
            res = max(res, solve(i + 1, t, 2, k, prices, dp));
            res = max(res, -1LL * prices[i] + solve(i + 1, t + 1, 0, k, prices, dp));
        }

        return res;
    }

public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        vector<vector<vector<long long>>> dp(
            n,
            vector<vector<long long>>(k + 1, vector<long long>(3, LLONG_MIN))
        );

        return solve(0, 0, 0, k, prices, dp);
    }
};
