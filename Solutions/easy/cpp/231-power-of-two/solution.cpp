class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        double logValue = std::log2(n);
        return std::floor(logValue) == logValue; 
    }
};