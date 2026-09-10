class Solution {
public:
    int countBinarySubstrings(string s) {
        const int n = s.size();
        
        int left = 0, leftGroup = 0;
        char leftChar = s[0];
        
        while(left < n && s[left] == leftChar){
            ++leftGroup;
            ++left;
        }
        
        int right = left, rightGroup = 0, ans = 0;
        while(right < n){
            // Expand right as far as possible
            char rightChar = leftChar == '0' ? '1' : '0';
            while(right < n && s[right] == rightChar){
                ++rightGroup;
                ++right;
            }

            ans += min(leftGroup, rightGroup);

            leftChar = rightChar;
            leftGroup = rightGroup;
            rightGroup = 0;
        }

        return ans;
    }
};