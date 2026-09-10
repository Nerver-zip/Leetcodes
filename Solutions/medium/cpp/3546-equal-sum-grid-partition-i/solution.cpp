using ll = long long;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<ll> rowSum(m, 0), colSum(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
        
        vector<ll> prefix_rowSum(m, 0);
        vector<ll> prefix_colSum(n, 0);
        
        prefix_rowSum[0] = rowSum[0];
        for(int i = 1; i < m; ++i)
            prefix_rowSum[i] = prefix_rowSum[i-1] + rowSum[i];
        
        prefix_colSum[0] = colSum[0];
        for(int i = 1; i < n; ++i)
            prefix_colSum[i] = prefix_colSum[i-1] + colSum[i];

        for(int i = 0; i < m-1; ++i){
            ll curr = prefix_rowSum[i];
            if(curr == prefix_rowSum.back() - curr)
                return true;
        }

        for(int i = 0; i < n-1; ++i){
            ll curr = prefix_colSum[i];
            if(curr == prefix_colSum.back() - curr)
                return true;
        }

        return false;
    }
};