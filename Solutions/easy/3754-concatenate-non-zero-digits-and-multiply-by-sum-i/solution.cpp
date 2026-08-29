using ll = long long;

class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        string s1;
        int mul = 0;
        for(char c : s){
            if(c != '0'){
                s1 += c;
                mul += c - '0';
            }
        }

        if(s1.size() == 0)
            return 0;

        ll res = stoll(s1);

        return res * mul ;
    }
};