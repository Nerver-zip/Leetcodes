class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len = tamanho do intervalo
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                for (int k = l; k < r; k++) {
                    int leftSum = pref[k + 1] - pref[l];
                    int rightSum = pref[r + 1] - pref[k + 1];

                    if (leftSum < rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][k]
                        );
                    }
                    else if (leftSum > rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[k + 1][r]
                        );
                    }
                    else {
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + max(dp[l][k], dp[k + 1][r])
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};