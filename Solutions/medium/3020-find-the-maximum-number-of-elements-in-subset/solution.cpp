using ll = long long;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int one_count = 0;
        
        unordered_map<ll,int> freq;
        int ans = 0;

        for(int n : nums)
            if(n == 1)
                ++ans;
            else
                ++freq[n];

        if(ans > 0 && ans % 2 == 0)
            --ans;
        
        auto calc = [&](ll x){

            int len = 1;

            while(freq[x] >= 2){

                if(x > 1e9 / x)
                    break;

                ll nxt = x * x;

                if(!freq.count(nxt))
                    break;

                len += 2;
                x = nxt;
            }

            return len;
        };
        
        for(const auto& [n, _] : freq)
            ans = max(ans, calc(n));

        return ans;
    }
};