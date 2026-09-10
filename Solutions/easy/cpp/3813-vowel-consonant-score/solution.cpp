class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowels = 0, consonants = 0;
        
        for (char c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                ++vowels;
            else if(c != ' ' && c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5'
                   && c != '6' && c != '7' && c != '8' && c != '9')
                ++consonants;
        }

        return consonants == 0 ? 0 : vowels/consonants;
    }
};