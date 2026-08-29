class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        using ll = long long;
        const int N = stations.size();
        vector<ll> prefix(N + 1);
        vector<ll> prefix2(N + 1);

        // Diff array, lazy range updates
        for (int i = 0; i < N; ++i) {
            prefix[max(0, i - r)] += (ll)stations[i];
            prefix[min(N, i + r + 1)] -= (ll)stations[i];
        }
        
        // Total power currently
        ll maximum = prefix[0];
        for(int i = 1; i < N; ++i){
            prefix[i] += prefix[i-1];
            maximum = max(maximum, prefix[i]);
        }

        auto check = [&](ll x) {
            ll used = 0;              
            vector<ll> add(N + 1, 0);             
            ll extra = 0;                         
            for (int i = 0; i < N; ++i) {
                extra += add[i]; // update active boost

                ll current = prefix[i] + extra;
                if (current < x) {
                    ll need = x - current;

                    if (used + need > k) 
                        return false;

                    used += need;
                    extra += need;
                    if (i + 2 * r + 1 < N) // greedly places boost as further as possible
                        add[i + 2 * r + 1] -= need; 
                }
            }
            return true;
        };

        ll left = 0, right = maximum + k, ans = 0;
        while (left <= right) {
            ll mid = left + (right - left)/2;
            if(check(mid)){
                left = mid + 1;
                ans = mid;
            }
            else
                right = mid - 1;
        }

        return ans;
    }
};