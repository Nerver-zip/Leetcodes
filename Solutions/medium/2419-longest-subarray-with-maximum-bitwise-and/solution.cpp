class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target = *max_element(nums.begin(), nums.end());

        int ans = 1, curr = nums[0] == target ? 1 : 0;
        for (int i = 1; i < nums.size(); ++i) {
            if(curr == 0 && nums[i] == target)
                ++curr;
            else if (nums[i] == target && nums[i-1] == target)
                ++curr;
            else 
                curr = 0;
            ans = max(ans, curr);
        }
        return ans;
    }
};