constexpr int MOD = 1000000007; 
using ll = long long;
class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans = 0;

        for(uint x = 1; x <= n; ++x){
            ans = ans << bit_width(x);
            ans |= x;
            ans %= MOD;
        }

        return ans;
    }
};