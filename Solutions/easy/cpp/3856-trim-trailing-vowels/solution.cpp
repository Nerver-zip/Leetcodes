class Solution {
public:
    string trimTrailingVowels(string s) {    
        int idx = -1;
        for(int i = s.size()-1; i >= 0; --i){
            if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
                idx = i;
                break;
            }
        }

        return string(s.begin(), s.begin() + idx + 1);
    }
};
