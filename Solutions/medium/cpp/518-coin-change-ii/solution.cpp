class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);

        const long long MOD = INT_MAX + 42;

        dp[0] = 1;
        for(int coin : coins){
            for(int sum = coin; sum <= amount; ++sum){
                if(dp[sum - coin] != 0)
                    dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
            }
        }

        return dp[amount];
    }
};