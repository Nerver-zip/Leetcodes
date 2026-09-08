class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int size = nums.size();
        
        //dp[i][j]: maximum possible sum starting in the position i 
        //in the array where the current sum modulo 3 is equal to r
        vector<vector<int>> dp(size, vector<int>(3, -1));

        dp[0][0] = 0;                 // do not take
        dp[0][nums[0] % 3] = nums[0]; // take nums[0]
        
        for (int i = 1; i < size; ++i){
            for (int r = 0; r < 3; ++r) {
                dp[i][r] = dp[i-1][r]; //dont take anything else
            }
            
            for (int r = 0; r < 3; ++r) {
                if(dp[i-1][r] != -1){ // if we can get to this state
                    //for each remainder j in pos i
                    dp[i][(r+nums[i]) % 3] = max(dp[i][(r+nums[i])%3], dp[i-1][r] + nums[i]);
                }                    
            }
        }

        return dp[size-1][0];
    }
};