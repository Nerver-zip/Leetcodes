class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int ROWS = obstacleGrid.size();
        const int COLS = obstacleGrid[0].size();
        vector<vector<long long>> dp(ROWS, vector<long long> (COLS,0));

        if (obstacleGrid[0][0] == 1 || obstacleGrid[ROWS-1][COLS-1] == 1 || ROWS > 1 && COLS > 1 && obstacleGrid[0][1] == 1 && obstacleGrid[1][0] == 1) 
            return 0;
    
        for (int i = 0; i < COLS; i++){
            if (obstacleGrid[0][i] == 1) 
                break;
            dp[0][i] = 1;
        }
            
        for (int i = 0; i < ROWS; i++){
            if (obstacleGrid[i][0] == 1) 
                break;
            dp[i][0] = 1;
        }
        
        for (int i = 1; i < ROWS; i++)
        {
            for (int j = 1; j < COLS; j++)
            {
                if (obstacleGrid[i][j] == 1) 
                    continue;
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[ROWS-1][COLS-1];
    }
};