class Solution {
public:
    int maxProduct(int n) {
        int ans = 0;
        vector<int> digits;

        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }

        std::ranges::sort(digits, std::greater{});

        return digits[0] * digits[1];
    }
};