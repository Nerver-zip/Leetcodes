class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq_letters(26, 0);
        vector<int> freq_digits(10, 0);
        unordered_set<char> unique;
        
        for(char c : s){
            if(c >= 'a' && c <= 'z')
                ++freq_letters[c - 'a'];
            else
                ++freq_digits[c - '0'];
            unique.insert(c);
        }
        
        
        int ans = 0;
        
        unordered_set<char> used;

        for(char c : unique){
            char m;
            
            if(!used.count(c)){
                
                
                if(c >= 'a' && c <= 'z'){
                    int idx = c - 'a';
                    m = 25 - idx + 'a';

                    if(used.count(m))
                        continue;
                        
                    ans += abs(freq_letters[c - 'a'] - freq_letters[m - 'a']);
                }
                else{
                    int idx = c - '0';
                    m = 9 - idx + '0';
                    if(used.count(m))
                        continue;
                    
                    ans += abs(freq_digits[c - '0'] - freq_digits[m - '0']);
                }
                used.insert(c);
                used.insert(m);
            }
        }

        return ans;
    }
};