class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<bool,bool>> special(26, pair<bool,bool>(false,false));

        int ans = 0;

        for(char c : word){
            if(c < 'a')
                special[c - 'A'].second = true;
            else
                special[c - 'a'].first = true;
        }
        
        for(const auto& [a,b] : special)
            if(a && b)
                ++ans;
                
        return ans;
    }
};