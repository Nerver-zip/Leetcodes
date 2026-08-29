class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);
        
        int x = 0;

        for (int i = 31; i >= 0; --i)
        {
            if (setBits == 0)
                break;
            if(num1 & (1 << i)){
                x |= (1 << i);
                setBits--;
            }
        }

        for (int i = 0; i < 32; ++i)
        {
            if(setBits == 0)
                break;
            if(!(num1 & (1 << i))){
                x |= (1 << i);
                setBits--;
            }
        }
        return x;  
    }
};
