using ll = long long;
using i128 = __int128_t;

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        ll total_sum = 0;

        for(int n : nums)
            total_sum += n;

        i128 mul = 1;
        int ans = -1;

        for(int i = nums.size()-1; i >= 0; --i){
            total_sum -= nums[i];
            if(total_sum < mul)
                return ans;
            if(total_sum == mul)
                ans = i;
            mul *= nums[i];
        }

        return ans;
    }
};