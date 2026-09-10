
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int size = 0;
        int ans = INT32_MAX;
        for (int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            while (sum >= target)
            {
                size = right - left + 1;
                ans = min(ans, size);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};