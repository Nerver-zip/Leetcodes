class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total_sum)
            return 0;

        int K = target + total_sum;
        
        if(K & 1)
            return 0;

        K /= 2;

        // dp[i] = número de subconjuntos com soma == i
        vector<int> dp(K+1, 0);
        
        dp[0] = 1;
        for(int n : nums){
            for(int i = K; i >= n; --i)
                dp[i] += dp[i - abs(n)];
        }

        return dp[K];
    }
};