class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        array<int, 26> freq{};

        for(char c : s){
            ++freq[c - 'a'];
        }

        string ans;

        while(freq[y - 'a']-- > 0){
            ans += y;
        }
        
        while(freq[x - 'a']-- > 0){
            ans += x;
        }       

        for(int i = 0; i < 26; ++i){
            while(freq[i]-- > 0){
                ans += i + 'a';
            }
        }

        return ans;
    }
};