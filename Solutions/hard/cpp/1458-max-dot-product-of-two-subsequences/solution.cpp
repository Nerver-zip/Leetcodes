class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int prod = A[i] * B[j];

                int best = prod; // iniciar subsequência aqui

                if (i > 0 && j > 0)
                    best = max(best, prod + dp[i-1][j-1]);

                if (i > 0)
                    best = max(best, dp[i-1][j]);

                if (j > 0)
                    best = max(best, dp[i][j-1]);

                dp[i][j] = best;
            }
        }
        return dp[n-1][m-1];
    }
};