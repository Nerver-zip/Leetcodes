class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string cur = word;
        int ans = 0;
        
        // For ans to increase we need to find a sequence that repeats twice,
        // then three times etc
        while (sequence.find(cur) != string::npos) {
            ans++;
            cur += word;
        }
        return ans;
    }
};