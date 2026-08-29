class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Transforma stones em prefix sum.
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }

        // dp[n - 1]
        int dp = stones[n - 1];

        // Só precisamos ir até 1 porque a primeira
        // jogada precisa pegar pelo menos 2 pedras.
        for (int i = n - 2; i >= 1; --i) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};