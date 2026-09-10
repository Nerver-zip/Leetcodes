class Solution {
public:
    bool checkStrings(string s1, string s2) {
        const int n = s1.size();
        vector<int> s1Freq_odd(26, 0), s2Freq_odd(26, 0),
                    s1Freq_even(26, 0), s2Freq_even(26, 0);
        
        for(int i = 0; i < n; ++i){
            if(i & 1){
                ++s1Freq_odd[s1[i] - 'a'];
                ++s2Freq_odd[s2[i] - 'a'];
            }
            else{
                ++s1Freq_even[s1[i] - 'a'];
                ++s2Freq_even[s2[i] - 'a'];
            }
        }

        if(s1Freq_odd != s2Freq_odd)
            return false;

        return s1Freq_even == s2Freq_even;
    }
};