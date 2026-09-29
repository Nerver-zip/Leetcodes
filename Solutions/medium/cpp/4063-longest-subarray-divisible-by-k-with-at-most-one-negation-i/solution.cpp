using ll = long long;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            ll sum = 0;
            unordered_set<ll> set;

            for(int j = i; j < nums.size(); ++j){           
                
                // mod normalize
                sum = ((sum + nums[j]) % k + k) % k;
                ll r = ((2LL * nums[j]) % k + k) % k;
                set.insert(r);

                // to make remainder equal to 0 we need to find an element x which S - 2x == 0
                // S = 2x
                // if we can't, continue

                if(sum && !set.count(sum)){
                    continue;
                }
                
                // otherwise we have a valid subarray
                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};