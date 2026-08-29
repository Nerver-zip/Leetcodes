class Solution {
public:
    string reverseByType(string s) {
        string letters, special;

        for (char c : s) {
            if(c >= 'a' && c <= 'z')
                letters += c;
            else
                special += c;
        }

        reverse(letters.begin(), letters.end());
        reverse(special.begin(), special.end());

        string ans;
        int i = 0, j = 0;
        for (char c : s){
            if(c >= 'a' && c <= 'z'){
                ans += letters[i];
                ++i;
            }
            else{
                ans += special[j];
                ++j;
            }
        }

        return ans;
    }
};