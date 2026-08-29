class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const int M = grid.size();
        const int N = grid[0].size();
        vector<vector<int>> ans(M-k+1, vector<int> (N-k+1, 0));
        
        auto minDiff = [&](int r, int c){
            long long diff = INT32_MAX;
            for(int i = r; i < r + k; ++i){
                for(int j = c; j < c + k; ++j){
                    long long x = grid[i][j];
                    for(int l = r; l < r + k; ++l){
                        for(int m = c; m < c + k; ++m){
                            if(x == grid[l][m])
                                continue;
                            diff = min(diff, abs(x - (long long)grid[l][m]));   
                        }
                    }
                }
            }
            return diff;
        };
        
        for(int i = 0; i < ans.size(); ++i){
            for(int j = 0; j < ans[0].size(); ++j){
                ans[i][j] = minDiff(i,j);
                ans[i][j] = ans[i][j] == INT32_MAX ? 0 : ans[i][j];
            }
        }
        return ans;
    }
};