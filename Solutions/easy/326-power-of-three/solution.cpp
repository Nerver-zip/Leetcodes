class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double logValue =  std::log(n) / std::log(3); //Base-3 log of n
        return std::fabs(logValue - std::round(logValue)) < 1e-10;
    }
};