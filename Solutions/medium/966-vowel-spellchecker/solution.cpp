class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int> normalized; //Captial normalization
        unordered_map<string, int> vowelSub; //Capital + substituting vowels by a wildcard
        unordered_set<string> wordSet;

        auto isVowel = [](char c){
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };

        for (int i = 0; i < wordlist.size(); ++i) {
            string s;
            string vs;
            for (char c : wordlist[i]){
                s += tolower(c);
                if(isVowel(s.back()))
                   vs += '_';
                else
                   vs += s.back();
            }
            wordSet.insert(wordlist[i]);
            if(normalized.find(s) == normalized.end())
                normalized[s] = i;
            if(vowelSub.find(vs) == vowelSub.end())
                vowelSub[vs] = i;
        }
        
        vector<string> ans;
        
        for (auto& word : queries) {
            //Absolute check
            if(wordSet.find(word) != wordSet.end())
                ans.push_back(word);
            else
            {
                string s, vs;
                for (char& c : word){
                    s += tolower(c);
                    if(isVowel(s.back()))
                        vs += '_';
                    else
                        vs += s.back();
                }
                auto it = normalized.find(s);
                auto it2 = vowelSub.find(vs);
                //Capital only
                if(it != normalized.end())
                    ans.push_back(wordlist[it->second]);
                //Capital + Vowel Sub
                else if(it2 != vowelSub.end())
                    ans.push_back(wordlist[it2->second]);
                else //No match
                    ans.push_back("");
            }
        }
        return ans;
    }
};