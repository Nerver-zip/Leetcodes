class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int ans = 0, maxFreq = 0;
        
        array<int, 26> freq = {};

        for (int right = 0, left = 0; right < s.size(); ++right) {
            ++freq[s[right] - 'A'];
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
            while(right - left + 1 - maxFreq > k){
                --freq[s[left] - 'A'];
                ++left;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};