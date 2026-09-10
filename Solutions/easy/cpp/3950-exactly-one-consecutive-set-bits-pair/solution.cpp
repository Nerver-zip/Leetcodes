class Solution {
public:
    bool consecutiveSetBits(int n) {
        bitset<32> bits(n);

        int res = 0;

        bool ans = false;
        bool more = false;

        for(int i = 0; i < 32; ++i){
            if(bits[i])
                ++res;
            else
                res = 0;

            if(res == 2){
                if(ans)
                    return false;
                ans = true;
            }

            if(res > 2){
                more = true;
            }
        }

        return ans && !more;
    }
};