class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        memo.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(grid, 0, 0, grid[0][0] % k, k);
    }

private:
    vector<vector<vector<int>>> memo; //memo[i][j][value] = number of paths until cell {i,j} where sum of elements
                                      // on the path has a remainder of value when divided by k
    
    const int prime = 1e9 + 7;
    int solve(const vector<vector<int>>& grid, int i, int j, int rem, int k) {
        int m = grid.size(), n = grid[0].size();

        if (i == m - 1 && j == n - 1)
            return rem == 0 ? 1 : 0;

        if (memo[i][j][rem] != -1) 
            return memo[i][j][rem];

        long long ways = 0;

        // Down
        if (i + 1 < m) {
            int newRem = (rem + grid[i + 1][j]) % k;
            ways += solve(grid, i + 1, j, newRem, k);
        }

        // Right
        if (j + 1 < n) {
            int newRem = (rem + grid[i][j + 1]) % k;
            ways += solve(grid, i, j + 1, newRem, k);
        }

        return memo[i][j][rem] = ways % prime;
    }
};