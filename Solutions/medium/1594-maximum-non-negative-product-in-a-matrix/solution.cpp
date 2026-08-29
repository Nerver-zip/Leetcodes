constexpr int MOD = 1000000007; 

using ll = long long;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<pair<ll,ll>>> dp(m, 
               vector<pair<ll,ll>>(n, pair<ll,ll>(LLONG_MIN, LLONG_MAX)));
        
        dp[0][0].first = dp[0][0].second = grid[0][0];
        for(int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) {
                
                // came from left
                if(j > 0){
                    dp[i][j].first = max(grid[i][j] * dp[i][j-1].first, grid[i][j] * dp[i][j-1].second); 
                    dp[i][j].second = min(grid[i][j] * dp[i][j-1].first, grid[i][j] * dp[i][j-1].second); 
                }

                // came from top
                if(i > 0){
                    dp[i][j].first = max({grid[i][j] * dp[i-1][j].first, grid[i][j] * dp[i-1][j].second, dp[i][j].first}); 
                    dp[i][j].second = min({grid[i][j] * dp[i-1][j].first, grid[i][j] * dp[i-1][j].second, dp[i][j].second}); 
                }
            }
        }
        

        int ans = max(dp[m-1][n-1].first, dp[m-1][n-1].second) % MOD;

        return ans < 0 ? -1 : ans;
    }
};