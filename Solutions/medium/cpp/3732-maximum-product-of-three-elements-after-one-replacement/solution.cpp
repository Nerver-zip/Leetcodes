using ll = long long;

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());        
        
        return max({static_cast<ll>((ll)nums[0] * (ll)nums[N-1] * -1e5),
                    static_cast<ll>((ll)nums[0] * (ll)nums[1] * 1e5),
                    static_cast<ll>((ll)nums[N-1] * (ll)nums[N-2] * 1e5)
        });
    }
};