class Solution {
public:
    int minRotations(string s) {
        
        int ans = 0;
        char curr = '0';
        for(char c : s){
            ans += min(abs(curr - c), 10 - abs(curr - c));
            curr = c;
        }

        return ans;
    }
};