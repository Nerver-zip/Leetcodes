class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < mat.size(); ++i)
            for (int j = 0; j < mat[0].size(); ++j)
                if(mat[i][j])
                    dp[i][j] = j == 0 ? 1 : dp[i][j-1] + 1;

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int min_width = dp[i][j];
                    for (int k = i; k >= 0; k--) {
                        min_width = min(min_width, dp[k][j]);
                        if (min_width == 0) break;
                        res += min_width;
                    }
                }
            }
        }

        return res;
    }
};