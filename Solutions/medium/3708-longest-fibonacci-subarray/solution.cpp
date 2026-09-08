class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 1;
        int ans = 0, curr = 0;
        
        for (int i = 2; i < nums.size(); ++i) {
            if(nums[left] + nums[right] == nums[i])
                ++curr;
            else
                curr = 0;
            ans = max(ans, curr); ++left; ++right;
        }

        return ans > 0 ? ans + 2 : 2;
    }
};