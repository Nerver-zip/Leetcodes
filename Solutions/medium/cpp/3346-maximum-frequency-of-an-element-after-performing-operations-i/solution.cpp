class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int ans = 1;

        //1) Target is present in nums
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            // [v-k, v+k]
            int L = lower_bound(nums.begin(), nums.end(), v - k) - nums.begin();
            int R = upper_bound(nums.begin(), nums.end(), v + k) - nums.begin();
            int count = R - L;

            int sameL = lower_bound(nums.begin(), nums.end(), v) - nums.begin();
            int sameR = upper_bound(nums.begin(), nums.end(), v) - nums.begin();
            int same = sameR - sameL;

            ans = max(ans, same + min(count - same, numOperations));
            i = sameR - 1;
        }

        //2) Target is not present in nums: get largest window ≤ 2k
        {
            int bestWindow = 1;
            int L = 0;
            for (int R = 0; R < n; ++R) {
                while (nums[R] - nums[L] > 2 * k) ++L;
                bestWindow = max(bestWindow, R - L + 1);
            }
            ans = max(ans, min(bestWindow, numOperations));
        }

        return ans;
    }
};