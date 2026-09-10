
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        const int m = coins.size();
        const int n = coins[0].size();
        
        // dp[i][j][x] = max profit the robot can achieve starting at (0,0) up to (i,j) using x special ability
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e7)));
        
        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(j < n-1){
                    dp[i][j+1][0] = max(dp[i][j+1][0], coins[i][j+1] + dp[i][j][0]);
                    dp[i][j+1][1] = max({dp[i][j+1][1], coins[i][j+1] + dp[i][j][1], dp[i][j][0]});
                    dp[i][j+1][2] = max({dp[i][j+1][2], coins[i][j+1] + dp[i][j][2], dp[i][j][1]});
                }

                if(i < m-1){
                    dp[i+1][j][0] = max(dp[i+1][j][0], coins[i+1][j] + dp[i][j][0]);
                    dp[i+1][j][1] = max({dp[i+1][j][1], coins[i+1][j] + dp[i][j][1], dp[i][j][0]});
                    dp[i+1][j][2] = max({dp[i+1][j][2], coins[i+1][j] + dp[i][j][2], dp[i][j][1]});
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};