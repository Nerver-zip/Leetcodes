class Solution {
public:
    int n;
    vector<int> vals;
    vector<vector<int>> memo;

    int dfs(int i, int j) {
        //cant form triangle with less than two
        if (j - i < 2) 
            return 0;
        if (memo[i][j] != -1) 
            return memo[i][j];

        int best = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            //form a triangle and split the problem into two new ones
            int cost = vals[i] * vals[j] * vals[k] + dfs(i, k) + dfs(k, j); 
            best = min(best, cost);
        }
        return memo[i][j] = best;
    }

    int minScoreTriangulation(vector<int>& values) {
        vals = values;
        n = vals.size();
        memo.assign(n, vector<int>(n, -1));
        return dfs(0, n - 1);
    }
};