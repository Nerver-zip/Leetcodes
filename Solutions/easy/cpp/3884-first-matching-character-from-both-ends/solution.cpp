class Solution {
public:
    int firstMatchingIndex(string s) {
        const int n = s.size();
        for(int i = 0; i < s.size(); ++i){
            if(n-i-1 >= 0 && s[i] == s[n-i-1])
                return i;
        }
        return -1;
    }
};