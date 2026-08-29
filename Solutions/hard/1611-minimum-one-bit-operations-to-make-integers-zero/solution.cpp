class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)
            return 0;

        int k = std::__bit_width(static_cast<unsigned int>(n)) - 1;

        return ((1 << (k+1)) - 1 - minimumOneBitOperations((1 << k) ^ n)); 
    }
};