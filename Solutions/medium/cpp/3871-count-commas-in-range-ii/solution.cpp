using ll = long long;

// 1'000'000'000'000'000
class Solution {
public:
    long long countCommas(long long n) {
        ll ans = 0; 
         
        if(n > 999)
            ans += min((ll)999'999, n) - 999;

        if(n > 999'999)
            ans += (min((ll)999'999'999, n) - 999'999) * 2;
        
        if(n > 999'999'999){
            ans += (min((ll)999'999'999'999, n) - 999'999'999) * 3;
        }

        if(n > 999'999'999'999){
            ans += (min((ll)999'999'999'999'999, n) - 999'999'999'999) * 4;
        }
        if(n > 999'999'999'999'999){
            ans += (min((ll)999'999'999'999'999'999, n) - 999'999'999'999'999) * 5;
        }

        return ans;
    }
};