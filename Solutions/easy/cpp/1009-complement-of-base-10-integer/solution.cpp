class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;

        bitset<32> b(n);

        for(int i = 0; i < std::bit_width((uint)n); ++i)
            b[i].flip();

        return b.to_ullong();
    }
};