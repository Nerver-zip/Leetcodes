class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        
        dp[0][0][grid[0][0]] = true;
        
        for(int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) {
                for(int x = 0; x < 1024; ++x){
                    if(dp[i][j][x]){
                        if(i < m-1){
                            int next = x ^ grid[i+1][j];
                            dp[i+1][j][next] = true;
                        }

                        if(j < n-1){
                            int next = x ^ grid[i][j+1];
                            dp[i][j+1][next] = true;
                        }
                    }
                }
            }    
        }


        int ans = 1023;

        for(int i = 0; i < 1023; ++i)
            if(dp[m-1][n-1][i]){
                return i;
            }

        return ans;
    }
};