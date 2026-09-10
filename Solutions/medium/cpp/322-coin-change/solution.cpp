class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        
        dp[0] = 0;
        for(int coin : coins){
            for(int sum = coin; sum <= amount; ++sum){
                if(dp[sum - coin] != INT_MAX){
                    dp[sum] = min(dp[sum], dp[sum - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};