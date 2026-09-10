using ll = long long;
constexpr int MOD = 1000000007; 

class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        
        auto build = [](ll d, int w)->pair<int,int>{
            string s = to_string(d);
            
            string s1(s.begin(), s.begin() + w);
            string s2(s.begin() + w, s.end());
            
            return {stoll(s1), stoll(s2)};
        };
        
        ll ans = 0;

        for(ll n : nums){
            int width = n % 10;
            ll d = n / 10;

            auto [x, y] = build(d, width);

            ans = (ans + modexp(x, y)) % MOD;
        }
        
        return ans;
    }

private:
    static ll modexp(ll a, ll e) {
        ll r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }
};