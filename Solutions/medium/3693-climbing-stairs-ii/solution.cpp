class Solution {
private:
    int dfs(const vector<int>& costs, vector<int>& memo, int i, int n) {
        if (i == n) return 0;

        if (memo[i] != -1) 
            return memo[i];

        int ans = INT32_MAX;
        for (int jump = 1; jump <= 3; jump++) {
            int j = i + jump;
            if (j <= n) {
                int cost_j = costs[j-1]; // shift para 0-index
                ans = min(ans, cost_j + jump*jump + dfs(costs, memo, j, n));
            }
        }

        return memo[i] = ans;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n+1, -1);
        return dfs(costs, memo, 0, n);
    }
};