class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> lower, upper, digits, symbols;

        for(char c : password){
            if(c >= 'A' && c <= 'Z')
                upper.insert(c);
            else if(c >= 'a' && c <= 'z')
                lower.insert(c);
            else if(c >= '0' && c <= '9')
                digits.insert(c);
            else
                symbols.insert(c);
        }

        return lower.size() + upper.size() * 2 + digits.size() * 3 + symbols.size() * 5;
    }
};