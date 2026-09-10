class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int ROWS = triangle.size();
        vector<vector<int>> dp(ROWS);

        for (int i = 0; i < ROWS; ++i)
            dp[i].assign(triangle[i].size(), INT32_MAX);
        
        dp[0][0] = triangle[0][0];     
        for (int i = 0; i < ROWS-1; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[i+1][j] = min(dp[i+1][j], triangle[i+1][j] + dp[i][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1], triangle[i+1][j+1] + dp[i][j]);
            }
        }

        return *min_element(dp[ROWS-1].begin(), dp[ROWS-1].end());
    }
};