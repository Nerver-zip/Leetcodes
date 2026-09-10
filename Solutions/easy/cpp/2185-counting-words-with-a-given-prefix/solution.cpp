class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const auto& word : words)
        {
            if (pref.size() <= word.size())
            {
                for (int i = 0; i < pref.size(); i++)
                {
                    if (word[i] != pref[i])
                    {
                        break;
                    }
                    if (i == pref.size()-1)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};