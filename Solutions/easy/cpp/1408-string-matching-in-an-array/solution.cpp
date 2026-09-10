class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        
        for (const auto& currWord : words)
        {
            bool found = false;
            for (const auto& compWord : words)
            {
                if (currWord.size() < compWord.size() && !found)
                {
                    int j = 0;
                    bool hasNextFirstOccurance = false;
                    int lastIndex = 0;
                    for (int i = 0; i < compWord.size(); i++)
                    {
                        if (currWord[j] == compWord[i]){
                            if (compWord[i] == currWord[0] && lastIndex != i && !hasNextFirstOccurance)
                            {
                                lastIndex = i;
                                hasNextFirstOccurance = true;
                            }
                            j++;
                        }
                        else if (j > 0 && j < currWord.size())
                        {
                            j = 0;
                            if (currWord[j] == compWord[i])
                                j++;
                            else if (hasNextFirstOccurance)
                            {
                                i = lastIndex-1;
                                hasNextFirstOccurance = false;
                            }
                        }
                        if (j == currWord.size())
                        {
                            ans.push_back(currWord);
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        return ans;    
    }
};