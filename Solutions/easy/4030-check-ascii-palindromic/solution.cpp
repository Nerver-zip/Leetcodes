class Solution {
public:
    bool isPalindromic(string s) {
        string binary;
        
        for(char c : s){
            int x = c;
            bitset<8> bits(x);
            
            binary += bits.to_string();
        }

        return isPalindrome(binary);
    }

private:

    bool isPalindrome(const string& s){
        int left = 0, right = s.size()-1;

        while(left < right){
            if(s[left] != s[right]){
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};