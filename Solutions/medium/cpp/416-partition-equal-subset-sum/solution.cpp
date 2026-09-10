class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0);

        if(target & 1)
            return false;

        target /= 2;
        
        // dp[s] = can we reach s sum? 
        vector<bool> dp(target + 1, false);

        dp[0] = true;
        for(int n : nums){
            for(int s = target; s >= n; --s){
                dp[s] = dp[s] || dp[s - n];
            }
            if(dp[target])
                return true;
        }

        return dp[target];
    }
};