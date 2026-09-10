class Solution {
public:
    int minOperations(string s) {
        const int n = s.size();
        
        auto buildPattern = [&](bool start_zero){
            string pattern;
            if(start_zero)
                pattern.push_back('0');
            else
                pattern.push_back('1');

            for(int i = 1; i < s.size(); ++i){
                if(pattern.back() == '1')
                    pattern.push_back('0');
                else
                    pattern.push_back('1');
            }

            return pattern;
        };

        string s0 = buildPattern(0);
        string s1 = buildPattern(1);
        
        int diff0 = 0;
        int diff1 = 0;

        for(int i = 0; i < n; ++i){
            if(s[i] != s0[i])
                ++diff0;
            if(s[i] != s1[i])
                ++diff1;
        }

        return min(diff0, diff1);
    }
};