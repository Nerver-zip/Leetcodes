class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {        
        int one_count = 0;
        bool one = false;
        char last = 'x';
        int leftZeros = 0;
        int rightZeros = 0;
        
        int ans = 0;

        for(char c : s)
            if(c == '1')
                ++one_count;

        for(char c : s){
            if(c == '1'){
                
                if(one && last == '0'){
                    leftZeros = rightZeros;
                    rightZeros = 0;
                }
                
                one = true;
            }
            else if(c == '0' && !one){
                 ++leftZeros;
            }
            else if(c == '0' && one){
                ++rightZeros;
            }
            
            if(leftZeros && rightZeros){
                ans = max(ans, one_count + leftZeros + rightZeros);
            }
            else {
                ans = max(ans, one_count);
            }

            last = c;
        }

        
        return ans;
    }
};