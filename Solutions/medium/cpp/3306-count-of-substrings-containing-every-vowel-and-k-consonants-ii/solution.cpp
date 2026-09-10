class Solution {
private:
    
    bool allFrequenciesAtLeastOne(const std::unordered_map<char, int>& map) {
        for (const auto& [key, freq] : map)
        {
            if (freq == 0)
                return false;
        }
        return true;
    }

    bool isVowel(const char& c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    } 

    long long atLeastK(const string& word, int k){
        int size = word.size();
        std::unordered_map<char,int> vowelMap {
            {'a',0},
            {'e',0},
            {'i',0},
            {'o',0},
            {'u',0}
        };

        int left = 0;
        int consonants = 0;
        long long res = 0;

        //SW
        for (int right = 0; right < size; right++)
        {
            if (isVowel(word[right]))
                vowelMap[word[right]]++;
            else
                consonants++;
            while (allFrequenciesAtLeastOne(vowelMap) && consonants >= k)
            {
                res += size - right;
                if (isVowel(word[left]))
                    vowelMap[word[left]]--;
                else
                    consonants--;
                left++;
            }
        }
        return res;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word,k) - atLeastK(word,k+1);
    }
};