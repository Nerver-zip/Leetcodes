class Solution {
private:
    bool isPrefix(string prefix, string word){
        if (prefix.size() > word.size())
        {
            return false;
        }
        
        int i = 0;
        int j = 0;
        while (i < prefix.size())
        {
            if (prefix[i] != word[j])
            {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    bool isSuffix(string sufix, string word){
        if (sufix.size() > word.size())
        {
            return false;
        }
        
        int i = sufix.size()-1;
        int j = word.size()-1;
        while (i >= 0)
        {
            if (sufix[i] != word[j])
            {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        if (words.size() < 2)
        {
            return 0;
        }
        int count = 0;
        int j = 1;
        for (int i = 0; i < words.size()-1; i++)
        {
            for (int j = i+1; j < words.size(); j++)
            {
                if (isPrefix(words[i],words[j]) && isSuffix(words[i],words[j]))
                {
                    count++;
                }  
            } 
        }
        return count;
    }
};