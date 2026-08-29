class Solution {
private: 
    bool isPalindrome(const string& s, int left, int right){
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                //deleting left makes left == right
                if (s[left+1] == s[right])
                {
                    if (isPalindrome(s, left+1, right))
                        return true;
                }
                //deleting right makes right == left
                if (s[right-1] == s[left])
                {
                    if (isPalindrome(s, left, right-1))
                        return true;
                }
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};