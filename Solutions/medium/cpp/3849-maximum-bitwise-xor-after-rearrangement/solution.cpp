class Solution {
public:
    string maximumXor(string s, string t) {
        int zeros = 0, ones = 0;

        for(char c : t)
            if(c == '0')
                ++zeros;
            else
                ++ones;
        

        for(char& c : s){
            if(c == '0' && ones){
                c = '1';
                --ones;
            }
            else if(c == '1' && zeros){
                --zeros;
                continue;
            }
            else
                c = '0';
        }

        return s;
    }
};