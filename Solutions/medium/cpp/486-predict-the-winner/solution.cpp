class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // dp[l][r] = diferença máxima entre pontos do primeiro jogador - pontos do segundo jogador no intervalo l r
        vector<vector<long long>> dp(n, vector<long long>(n));

        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                dp[l][r] = max(
                    nums[l] - dp[l + 1][r],
                    nums[r] - dp[l][r - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;       
    }
};