class Solution {
public:
    int numberOfSpecialChars(string word) {
        const int n = word.size();

        vector<int> firstUpperOccurance(26, -1);
        vector<int> lastLowerOccurance(26, -1);
        
        for(int i = 0; i < n; ++i){
            if(word[i] < 'a'){
                if(firstUpperOccurance[word[i] - 'A'] == -1)
                    firstUpperOccurance[word[i] - 'A'] = i;
            }
            else {
                lastLowerOccurance[word[i] - 'a'] = i; 
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 26; ++i){
            if(firstUpperOccurance[i] == -1 || lastLowerOccurance[i] == -1)
                continue;
            if(lastLowerOccurance[i] < firstUpperOccurance[i])
                ++ans;
        }

        return ans;
    }
};