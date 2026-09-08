class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;

        vector<int> incr_len(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                incr_len[i] = incr_len[i + 1] + 1;
            }
        }

        for (int i = 0; i + 2 * k <= n; ++i) {
            if (incr_len[i] >= k && incr_len[i + k] >= k) {
                return true;
            }
        }

        return false;
    }
};