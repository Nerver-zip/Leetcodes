class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> dp(ROWS, vector<int>(COLS, 0));

        //Init rows
        int starting = 0;
        for (int i = 0; i < ROWS; ++i){
            dp[i][0] = grid[i][0] + starting;
            starting = dp[i][0];
        }
            
        //Init cols
        starting = 0;
        for (int i = 0; i < COLS; ++i){
            dp[0][i] = grid[0][i] + starting;
            starting = dp[0][i];
        }
        
        for (int i = 1; i < ROWS; ++i)
            for (int j = 1; j < COLS; ++j)
                dp[i][j] = min(grid[i][j] + dp[i-1][j], grid[i][j] + dp[i][j-1]);
        return dp[ROWS-1][COLS-1];
    }
};