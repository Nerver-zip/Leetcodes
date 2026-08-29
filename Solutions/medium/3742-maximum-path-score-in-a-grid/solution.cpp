class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();

        k = min(k, m + n - 2);

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1))); 
        dp[0][0][0] = 0;
                
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                
                int cost = grid[i][j] == 0 ? 0 : 1;
                
                for(int c = 0; c <= k; ++c){
                    if(i > 0 && c + cost <= k && dp[i-1][j][c] != -1){
                        dp[i][j][c+cost] = max(dp[i][j][c+cost], grid[i][j] + dp[i-1][j][c]);
                    }
                    if(j > 0 && c + cost <= k && dp[i][j-1][c] != -1){
                        dp[i][j][c + cost] = max(dp[i][j][c+cost], grid[i][j] + dp[i][j-1][c]);
                    }
                }
            }
        }

        int ans = -1;
        for(int i = 0; i <= k; ++i){
            if(dp[m-1][n-1][i] != -1)
                ans = max(ans, dp[m-1][n-1][i]);
        }

        return ans;
    }
};