class Solution {
public:
    int magicalString(int n) {
        int oneCount = 1;
        
        int next = 1; 
        
        string s = "122";
        
        int i = 2;
        while(s.size() < n){
            if(s[i] == '2' && next == 1){
                oneCount += 2;
                s += "11";
                next = 2;
            }
            else if(s[i] == '1' && next == 2){
                s += "2";
                next = 1;
            }
            else if(s[i] == '1' && next == 1){
                ++oneCount;
                s += "1";
                next = 2;
            }
            else if(s[i] == '2' && next == 2){
                s += "22";
                next = 1;
            }
            ++i;

            if(s.size() > n && s.back() == '1')
                --oneCount;
        }
        return oneCount;
    }
};