class Solution {
public:
    int smallestNumber(int n) {
        for (int x = n; x <= 511; ++x) {
            int count = __builtin_popcount(x);
            int mask = (1ULL << count) - 1;

            if((mask & x) == mask)
                return x;
        }        

        return 1023;
    }
};