using ll = long long;
class Solution {
public:
    int minimumK(vector<int>& nums) {
        auto check = [&](ll k){
            ll operations = 0;
            
            for (ll n : nums) {
                if(n == 0) continue;
                int operationsNeeded = n/k;
                
                if(n % k != 0)
                    ++operationsNeeded;

                if((n - operationsNeeded * k ) > 0)
                    return false;
                
                operations += operationsNeeded;
            }

            return operations <= k * k;
        };


        ll left = 1, right = *max_element(nums.begin(), nums.end()) + nums.size();
        ll ans = right;

        while (left <= right) {
            ll mid = left + (right-left)/2;

            if(check(mid)){
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};