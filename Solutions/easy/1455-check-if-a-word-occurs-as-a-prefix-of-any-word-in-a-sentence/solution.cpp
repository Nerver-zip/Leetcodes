class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int sentenceCount = 1;
        int count = 0;
        int i = 0;
        bool flag = true;

        for(auto s : sentence){
            if (s == searchWord[i] && flag)
            {
                count++;
                i++;
            }
            else
            {
                flag = false;
            }
            if (s == ' ')
            {
                sentenceCount++;
                count = 0;
                i = 0;
                flag = true;
            }
            if (count == searchWord.size())
            {
                return sentenceCount;
            }
        }
        return -1;
    }
};