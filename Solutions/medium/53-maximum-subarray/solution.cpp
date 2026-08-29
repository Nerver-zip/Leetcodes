class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size()); //dp[i] = maxSubArray sum ending on i;
        
        // Two options: Start a fresh subarray sum
        //              Continue with the last one
        // We know it's better to start a fresh array 
        // when nums[i] is greater than the accumulated sum up to i
        
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i)
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
    
        return *max_element(dp.begin(), dp.end());
    }   
};