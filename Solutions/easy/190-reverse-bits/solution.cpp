class Solution {
public:
    int reverseBits(int n) {
        bitset<32> src(n);
        bitset<32> dst;
        
        for(int i = 0; i < 32; ++i)
            dst[31 - i] = src[i];

        return dst.to_ullong();
    }
};