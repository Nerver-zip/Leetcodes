class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> letterSet;
        const int n = text.size();

        for (char c : brokenLetters)
            letterSet.insert(c);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(letterSet.count(text[i]))
                while(i < n && text[i] != ' ')
                    ++i;
            else if(text[i] == ' ' || i == n - 1)
                ++ans;
        }
        return ans;
    }
};