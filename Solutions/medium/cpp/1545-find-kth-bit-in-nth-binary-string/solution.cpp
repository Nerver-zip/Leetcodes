class Solution {
public:
    Solution(){
        if(s.empty()){
            s += '0';
            for(int i = 1; i <= 20; ++i){
                s += '1';
                int idx = s.size()-2;
                while(idx >= 0){
                    if(s[idx] == '0')
                        s += '1';
                    else
                        s += '0';
                    --idx;
                }
            }
        }
    }
    
    char findKthBit(int n, int k) {
        return s[k-1];    
    }

private:
    static inline string s;
};