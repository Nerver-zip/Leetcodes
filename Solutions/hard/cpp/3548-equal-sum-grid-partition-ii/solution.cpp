using ll = long long;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<ll> rowSum(m, 0), colSum(n, 0);
        
        unordered_map<int,int> bottomFreq, topFreq, leftFreq, rightFreq;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                ++bottomFreq[grid[i][j]]; 
                ++rightFreq[grid[i][j]];
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

        if(m == 1) {
            ll total = prefix_colSum.back();
            ll curr = 0;

            for(int j = 0; j < n-1; ++j){
                curr += grid[0][j];
                ll other = total - curr;

                if(curr == other) return true;

                ll diff = abs(curr - other);

                if(curr > other) {
                    // left: [0 ... j]
                    if(diff == grid[0][0] || diff == grid[0][j])
                        return true;
                } else {
                    // right: [j+1 ... n-1]
                    if(diff == grid[0][j+1] || diff == grid[0][n-1])
                        return true;
                }
            }
            return false;
        }
        

        if(n == 1) {
            ll total = prefix_rowSum.back();
            ll curr = 0;

            for(int i = 0; i < m-1; ++i){
                curr += grid[i][0];
                ll other = total - curr;

                if(curr == other) return true;

                ll diff = abs(curr - other);

                if(curr > other) {
                    // top: [0 ... i]
                    if(diff == grid[0][0] || diff == grid[i][0])
                        return true;
                } else {
                    // bottom: [i+1 ... m-1]
                    if(diff == grid[i+1][0] || diff == grid[m-1][0])
                        return true;
                }
            }
            return false;
        }

        
        for(int i = 0; i < m-1; ++i){
            for(int j = 0; j < n; ++j){
                int x = grid[i][j];
                if(--bottomFreq[x] == 0)
                    bottomFreq.erase(x);
                ++topFreq[x];
            }

            ll split1 = prefix_rowSum[i];
            ll split2 = prefix_rowSum.back() - split1;

            if(split1 == split2)
                return true;

            ll diff = abs(split1 - split2);

            if(split1 > split2) {
                if(i == 0) {
                    // top é 1D -> só bordas
                    if(diff == grid[0][0] || diff == grid[0][n-1])
                        return true;
                }
                else {
                    if(topFreq[diff] > 0){

                        if(n > 2) return true;    

                        // n == 2 -> só bordas da região top
                        if(diff == grid[0][0] || diff == grid[0][n-1] ||
                           diff == grid[i][0] || diff == grid[i][n-1])
                            return true;
                    }
                }
            }
            else{
                if(i == m-2) {
                    // bottom é 1D -> só bordas
                    if(diff == grid[m-1][0] || diff == grid[m-1][n-1])
                        return true;
                }
                else {
                    if(bottomFreq[diff] > 0){
                        if(n > 2) return true;

                        // n == 2 -> só bordas da região bottom
                        if(diff == grid[i+1][0] || diff == grid[i+1][n-1] ||
                           diff == grid[m-1][0] || diff == grid[m-1][n-1])
                            return true;
                    }
                }
            }
        }
        
        for(int j = 0; j < n-1; ++j){
            for(int i = 0; i < m; ++i){
                int x = grid[i][j];
                if(--rightFreq[x] == 0)
                    rightFreq.erase(x);
                ++leftFreq[x];
            }

            ll split1 = prefix_colSum[j];
            ll split2 = prefix_colSum.back() - split1;

            if(split1 == split2)
                return true;

            ll diff = abs(split1 - split2);
            
            if(split1 > split2) {
                if(j == 0) {
                    // left é 1D -> só bordas
                    if(diff == grid[0][0] || diff == grid[m-1][0])
                        return true;
                }
                else {
                    if(leftFreq[diff] > 0){
                        if(m > 2) return true;

                        // m == 2 -> só bordas da região left
                        if(diff ==grid[0][0] || diff == grid[m-1][0] ||
                           diff == grid[0][j] || diff == grid[m-1][j])
                            return true;
                    }
                }
            }
            else{
                if(j == n-2) {
                    // right é 1D -> só bordas
                    if(diff == grid[0][n-1] || diff == grid[m-1][n-1])
                        return true;
                }
                else {
                    if(rightFreq[diff] > 0){
                        if(m > 2) return true;

                        // m == 2 -> só bordas da região right
                        if(diff == grid[0][j+1] || diff == grid[m-1][j+1] ||
                           diff == grid[0][n-1] || diff == grid[m-1][n-1])
                            return true;
                    }
                }
            }
        }

        return false;
    }
};