class Solution {
public:
    int reverse(long long x) {
        const int upper_bound = INT32_MAX;
        const int lower_bound = INT32_MIN;
        
        vector<int> digits;
        long long ans = 0;
        bool negative = abs(x) != x ? true : false;
        x = abs(x);

        while(x){
            digits.push_back(x % 10);
            x /= 10;
        }

        int exp = digits.size()-1;

        for (int i = 0; i < digits.size(); ++i) {
            ans += digits[i] * pow(10, exp);
            --exp;
            if(ans > upper_bound || ans < lower_bound && negative){
                return 0;
            }
        }

        if(negative){
            ans *= -1;
        }

        return ans > upper_bound ? 0 : ans < lower_bound ? 0 : (int)ans;
    }
};