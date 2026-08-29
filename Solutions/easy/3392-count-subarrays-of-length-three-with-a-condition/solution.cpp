class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int right = 0;
        int left = 0;
        int ans = 0;
        for (right; right < nums.size(); right++)
        {
            if (right+1 - left == 3)
            {
                if (nums[right] + nums[left] == nums[left+1]/2.0)
                    ans++;
                left++;
            }
        }
        return ans;
    }
};