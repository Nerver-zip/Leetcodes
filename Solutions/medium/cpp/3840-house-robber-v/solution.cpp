using ll = long long;
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        const int n = nums.size();
        vector<ll> dp(nums.begin(), nums.end()); // dp[i] = max val we can have up until i
        
        for(int i = 1; i < nums.size(); ++i){
            if(colors[i] != colors[i-1])
                dp[i] = max(dp[i], nums[i] + dp[i - 1]); // can take adjacent if colors are different
            else
                dp[i] = max(dp[i], dp[i-1]); // skip, stay with max
            
            if(i > 1)
                dp[i] = max(dp[i], nums[i] + dp[i-2]);
        }
        return dp[n-1];
    }    
};