class Solution {
public:
    int binaryGap(int n) {
        bitset<32> bits(n);
        int msb = 31 - __builtin_clz(n);
        int lastPos = msb;
        
        int ans = 0;
        for(int i = msb; i >= 0; --i){
            if(bits[i] == 1){
                ans = max(ans, lastPos - i);
                lastPos = i;
            }
        }

        return ans;
    }
};