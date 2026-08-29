class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp;

        for(int i = 1; i <= query_row+1; ++i){
            dp.push_back(vector<double>(i, 0.0));
        }
        
        dp[0][0] = poured;
        for (int i = 1; i < dp.size(); ++i) {
            for(int j = 0; j < dp[i].size(); ++j){
                if(j > 0 && j < i){
                    dp[i][j] += dp[i-1][j] > 1 ? (dp[i-1][j] - 1)/2.0 : 0;
                    dp[i][j] += dp[i-1][j-1] > 1 ? (dp[i-1][j-1] - 1)/2.0 : 0;
                }
                else
                    if(j == i)
                        dp[i][j] = dp[i-1][j-1] > 1 ? (dp[i-1][j-1] - 1)/2.0 : 0;     
                    else 
                        dp[i][j] = dp[i-1][j] > 1 ? (dp[i-1][j] - 1)/2.0 : 0;
            }
        }

        return dp[query_row][query_glass] > 1 ? 1 : dp[query_row][query_glass];
    }
};