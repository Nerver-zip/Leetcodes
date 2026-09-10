
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> frequencyConsonant(26, 0);
        vector<int> frequencyVowel(26, 0);

        auto isVowel = [](char c){
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (char c : s) {
            if(isVowel(c))
                ++frequencyVowel[c - 'a'];
            else
                ++frequencyConsonant[c - 'a'];
                
        }

        return *max_element(frequencyConsonant.begin(), frequencyConsonant.end()) + 
               *max_element(frequencyVowel.begin(), frequencyVowel.end());
    }
};