constexpr int MOD = 1000000007; 
using ll = long long;
class Solution {
public:
    int numOfWays(int n) {
        ll aba = 6, abc = 6;

        for (int i = 1; i < n; ++i) {
            ll next_aba = (3 * aba + 2 * abc) % MOD;
            ll next_abc = (2 * aba + 2 * abc) % MOD;

            aba = next_aba;
            abc = next_abc;
        }

        return (aba + abc) % MOD;
    }
};
