class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        const int n = nums.size();

        vector<int> dp(n, -1); //dp[i] = max jumps required to get to pos i
        
        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(dp[i] == -1)
                    continue;
                int diff = nums[j] - nums[i];
                if(-target <= diff && diff <= target)
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }

        return dp[n-1];
    }
};
