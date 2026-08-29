class Solution {
private:
    const int MOD = 1e9 + 7;

    int dfs(int n, const int x, vector<vector<int>>& memo, int i, int sum){
        if(sum == n)
            return 1;
        if(sum > n)
            return 0;
        if(pow(i,x) > n - sum)
            return 0;
        if(memo[i][sum] != -1)
            return memo[i][sum];

        return memo[i][sum] = (dfs(n, x, memo, i+1, sum) + dfs(n, x, memo, i+1, sum + pow(i,x))) % MOD;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        return dfs(n, x, memo, 1, 0);
    }
};