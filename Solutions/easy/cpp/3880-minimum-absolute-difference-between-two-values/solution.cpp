class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT32_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if(nums[i] == 1 && nums[j] == 2)
                    ans = min(ans, abs(i - j));
            }
        }

        return ans == INT32_MAX ? -1 : ans;
    }
};