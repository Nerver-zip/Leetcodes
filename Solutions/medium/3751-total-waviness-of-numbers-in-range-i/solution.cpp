class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto peakCount = [](int n){
            string s = to_string(n);
            int waviness = 0;

            for(int i = 1; i < s.size()-1; ++i)
                if(s[i-1] < s[i] && s[i] > s[i+1] || s[i-1] > s[i] && s[i] < s[i+1])
                    ++waviness;

            return waviness;
        };
        
        int ans = 0;

        for(int n = num1; n <= num2; ++n)
            ans += peakCount(n);

        return ans;
    }
};