class Solution {
public:
    bool detectCapitalUse(string word) {
        bool upperCase = false, lowerCase = false;
        if(word[0] > 'Z')
            lowerCase = true;
        for(int i = 1; i < word.size(); ++i){
            if(word[i] < 'a')
                upperCase = true;
            else if(word[i] > 'Z')
                lowerCase = true;
        
            if(lowerCase && upperCase)
                return false;
        }

        return true;
    }
};
