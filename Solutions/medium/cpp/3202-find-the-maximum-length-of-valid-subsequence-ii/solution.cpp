class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 1;

        for (int val = 0; val < k; ++val) {
            vector<int> dp(k, 0);

            for (int x : nums) {
                int modX = x % k;
                int prev = (val - modX + k) % k;

                int best = dp[prev] + 1;
                dp[modX] = max(dp[modX], best);
                res = max(res, dp[modX]);
            }
        }
        return res;
    }
};