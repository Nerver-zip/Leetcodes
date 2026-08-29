class Solution {
private:
    static inline unordered_set<char> validDigits = {
        '0','1','2','3','4','5','6','7','8','9',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };
    static inline unordered_set<char> vowel = {'a','e','i','o','u', 'A','E','I','O','U'};
    static inline unordered_set<char> consonant = {
        'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z',
        'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'
    };
public:
    bool isValid(string word) {
        bool isMinLen = word.size() > 2 ? true : false;
        bool hasVowel = false;
        bool hasConsonant = false;

        for(const auto& c : word){
            if(!validDigits.count(c))
                return false;
            if(consonant.count(c))
                hasConsonant = true;
            else if(vowel.count(c))
                hasVowel = true;
        }
        return isMinLen && hasVowel && hasConsonant;
    }
};