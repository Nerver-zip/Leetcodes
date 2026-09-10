using ll = long long;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll left = 0;
        ll right = accumulate(batteries.begin(), batteries.end(), 0LL) / n;

        ll ans = 0;
        while (left <= right) {
            ll mid = left + (right-left)/2;
            
            if(check(batteries, mid, n)){
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        return ans;
    }
private:

    // Sum of min(b_i, t) >= n * t
    // in order to keep n computers operating simultaneously for t seconds
    bool check(const vector<int>& batteries, ll t, ll n){
        ll total = 0;
        for (ll battery : batteries)
            total += min(battery, t);
        
        return total >= (n * t);
    }
};