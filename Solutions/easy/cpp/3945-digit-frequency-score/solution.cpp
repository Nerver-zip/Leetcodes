class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10);
        
        string s = to_string(n);

        for(char c : s){
            ++freq[c - '0'];
        }

        int ans = 0;

        for(int d = 0; d < 10; ++d)
            ans += d * freq[d];

        return ans;
    }
};