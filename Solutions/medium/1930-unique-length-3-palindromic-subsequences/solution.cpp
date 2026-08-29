class Solution {
public:
    int countPalindromicSubsequence(string s) {

        array<int, 26> right{};
        unordered_set<string> unique;
        array<bool, 26> left{};

        for (int i = 2; i < s.size(); ++i)
            ++right[s[i] - 'a'];
        
        left[s[0] - 'a'] = true; 
        for (int mid = 1; mid < s.size()-1; ++mid) {
            
            for (int i = 0; i < 26; ++i) {
                if(left[i] && right[i]){
                    unique.insert(string(1, char(i + 'a')) + s[mid] + std::string(1, char(i + 'a'))); 
                }
            }

            --right[s[mid+1] - 'a'];
            left[s[mid] - 'a'] = true;
        }

        return unique.size();
    }
};