using ll = long long;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<ll> prefix(k, LLONG_MAX/4);  // prefix[i % k] = minimum sum ending at i % k
                                           // so we can use this to maximize the answer
                                           // if we are at i = 6 is size 6 and k = 5
                                           // we want to remove the prefix[6 % 5] -> 1
                                           
        prefix[0] = 0; // no need to subtract anything if remainder is 0
        ll ans = LLONG_MIN, total = 0;

        for (int i = 0; i < nums.size(); ++i){
            total += nums[i];
            int size = i + 1;
            ans = max(ans, total - prefix[size % k]);
            prefix[size % k] = min(prefix[size % k], total);
        }
        
        return ans;
    }
};