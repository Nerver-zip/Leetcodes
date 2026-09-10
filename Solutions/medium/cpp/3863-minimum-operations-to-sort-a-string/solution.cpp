class Solution {
public:
    int minOperations(string s) {
        const int n = s.size();
        vector<int> freq(26, 0);

        char minChar = 'z', maxChar = 'a';
        bool violation = 0;
        
        char curr = s[0];
        for(char c : s){
            minChar = min(c, minChar);
            maxChar = max(c, maxChar);
            ++freq[c - 'a'];
            
            if(curr > c)
                violation = true;
            curr = c;
        }

        int max_char_freq = freq[maxChar - 'a'];
        int min_char_freq = freq[minChar - 'a'];

        // Ans can only be -1, 0, 1, 2 and 3
        
        // 0 case
        if(violation == 0)
            return 0;
        
        // -1 case
        if(s.size() == 2)
            return -1;
        
        // 1 case -> Starting or ending is correct
        if(minChar == s[0] || maxChar == s[n-1])
            return 1;

        // 3 Case -> Starting is max and ending is lowest
        // But only 1 ocurrance for each
        // e.g "zya"
        if(min_char_freq == 1 && max_char_freq == 1 && minChar == s[n-1] && maxChar == s[0])
            return 3;

        // Other than that its always two
        // e.g "zzya" -> "zayz" -> "ayzz"
        return 2;
    }
};