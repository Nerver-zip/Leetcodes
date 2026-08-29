class Solution {
public:
    int minFlips(string s) {
        int oneCount = 0, zeroCount = 0;

        for(char c : s){
            if(c == '1')
                ++oneCount;
            else
                ++zeroCount;
        }

        // important case: 100...01
        if(oneCount == 0 || zeroCount == 0 || oneCount == 1 || (oneCount == 2 && (s.front() == '1' && s.back() == '1')))
            return 0;

        
        // covers 100010001
        // min between flipping every 0 to one and everyone-1 to zero
        return s.front() == '1' && s.back() == '1' ? min(zeroCount, max(0, oneCount-2)) : 
                                                     min(zeroCount, max(0, oneCount-1));
    }
};