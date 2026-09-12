class Solution {
public:
    int minDays(int n) {
        vector<int> optimal{1};
        int streak = 1;

        while(optimal.back() < n){
            ++streak;
            optimal.push_back(optimal.back() + streak);
        }
        
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;
        for(int d = 0; d < optimal.size(); ++d){
            int days = d + 1;
            int val = optimal[d];

            for(int sum = val; sum <= n; ++sum){
                if(dp[sum - val] != INT_MAX){
                    dp[sum] = min(dp[sum], dp[sum - val] + days + 1);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n]-1;
    }
};