class Solution {
public:
    string smallestPalindrome(string s) {
        const int n = s.size();
        array<int,26> freq{};
        
        for(char c : s){
            ++freq[c - 'a'];
        }
        
        char odd = 'A';
        if(n & 1){
            for(int i = 0; i < 26; ++i){
                if(freq[i] & 1){
                    odd = i + 'a';
                    break;
                }
            }
        }
        
        string ans;

        for(int i = 0; i < 26; ++i){
            int left = freq[i]/2;
            while(left--){
                ans += i + 'a';
            }
        }

        string rev(ans.rbegin(), ans.rend());

        if(n & 1){
            return ans + odd + rev;
        }

        return ans + rev;
    }
};