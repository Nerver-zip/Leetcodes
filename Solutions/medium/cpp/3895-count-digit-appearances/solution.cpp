class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        array<int, 10> digits = {};
        
        auto getDigits = [&](int x){
            while(x){
                ++digits[x % 10];
                x /= 10;
            }
        };

        for(int x : nums)
            getDigits(x);

        return digits[digit];
    }
};