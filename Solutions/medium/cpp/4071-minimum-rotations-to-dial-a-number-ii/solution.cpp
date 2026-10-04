class Solution {
public:
    int minRotations(int n, string s) {
        vector<int> suffix(n+1, INT_MAX); // cost of reverted s[i...n] coming from s[i-1]  
        
        suffix[n] = 0;
        char curr = s[n-1];
        
        for(int i = n-1; i >= 0; --i){
            int rotations = min(abs(curr - s[i]), 10 - abs(curr - s[i])); 
            suffix[i] = suffix[i+1] + rotations;
            curr = s[i];
        }

        curr = '0';
        int offset = min(abs(s[n-1] - curr), 10 - abs(s[n-1] - curr));
        int ans = suffix[0] + offset;
        int prefix = 0;

        for(int i = 0; i < n; ++i){
            int rotations = min(abs(curr - s[i]), 10 - abs(curr - s[i]));
            prefix += rotations;

            int offset = min(abs(s[n-1] - s[i]), 10 - abs(s[n-1] - s[i]));
            ans = min(ans, prefix + suffix[i+1] + offset);
            curr = s[i];
        }

        return min(ans, prefix);
    }
};