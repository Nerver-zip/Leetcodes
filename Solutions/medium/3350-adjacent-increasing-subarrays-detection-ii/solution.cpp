class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> incr_len(n, 1);
        
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                incr_len[i] = incr_len[i + 1] + 1;
            }
        }
        
        auto solve = [&](int k){
            for (int i = 0; i + 2 * k <= n; ++i) {
                if (incr_len[i] >= k && incr_len[i + k] >= k) {
                    return true;
                }
            }
            return false;
        };

        int left = 0, right = n/2, ans = 0;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            if(solve(mid)){
                left = mid + 1;
                ans = mid;
            }
            else
                right = mid - 1;
        }
        
        return ans;
    }
};