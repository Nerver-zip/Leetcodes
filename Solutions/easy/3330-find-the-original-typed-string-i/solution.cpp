class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;

        if (word.size() == 1)
            return ans;
        
        for (int i = 1; i < word.size(); ++i)
            if(word[i] == word[i-1])
                ++ans;    
    
        return ans;
    }
};