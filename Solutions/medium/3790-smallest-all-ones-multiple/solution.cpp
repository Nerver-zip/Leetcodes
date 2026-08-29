using ll = long long;
class Solution {
public:
    int minAllOneMultiple(int k) {
        
        ll num = 0;
        
        unordered_set<ll> seen;
        
        int digits = 1;
        while (true) {
            num = num * 10 + 1;
            ll remainder = num % k; 

            if(remainder == 0)
                return digits;

            if(seen.count(remainder)) //cycle, ans = -1
                break;

            seen.insert(num % k);
            num %= k;
            ++digits;
        }
        
        return -1;
    }
};