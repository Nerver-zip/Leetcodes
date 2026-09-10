class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> suffix(n, 0);

        suffix.back() = nums.back();

        for(int i = n-2; i >= 0; --i){
            suffix[i] = min(suffix[i+1], nums[i]);
        }

        int maxPrefix = nums[0];
        int ans = n;

        for(int i = 0; i < n; ++i){
            maxPrefix = max(maxPrefix, nums[i]);

            int instability = maxPrefix - suffix[i];

            if(instability <= k){
                return i;
            }
        }

        return -1;
    }
};