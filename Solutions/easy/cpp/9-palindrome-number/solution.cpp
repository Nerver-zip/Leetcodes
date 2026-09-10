class Solution {
public:
    bool isPalindrome(int x) {
        
        string s = to_string(x);
        auto cp = s;
        reverse(cp.begin(), cp.end());
        
        return s == cp;
    }
};