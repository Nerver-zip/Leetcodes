class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string newWord;

        int i = 0;
        int j = 0;
        bool alternator = true;

        while (i < word1.size() && j < word2.size())
        {
            if (alternator)
            {
                newWord += word1[i];
                alternator = false;
                i++;
            }
            else
            {
                newWord += word2[j];
                alternator = true;
                j++;
            }
        }

        while (i < word1.size())
        {
            newWord += word1[i];
            i++;
        }
        while (j < word2.size())
        {
            newWord += word2[j];
            j++;
        }
        return newWord;
    }
};