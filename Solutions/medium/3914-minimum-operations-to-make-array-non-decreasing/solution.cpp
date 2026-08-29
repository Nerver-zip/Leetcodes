using ll = long long;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        const int n = nums.size();
        
        ll ans = 0;

        for(int i = 1; i < n; ++i)
            if(nums[i] < nums[i-1])
                ans += nums[i-1] - nums[i];

        return ans;
    }
};