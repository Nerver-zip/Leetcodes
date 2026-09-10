#define MODULO 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> letterFreqConst(26, 0);
        vector<long long> letterFreqMut(26, 0);

        for(const auto& c : s){
            letterFreqConst[c - 'a']++;
            letterFreqMut[c - 'a']++;
        }

        while (t--)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (letterFreqConst[i] == 0)
                    continue;
                bool z = i == 25 ? true : false;
                long long toTransform = letterFreqConst[i] % MODULO;
                letterFreqMut[i] -= toTransform;
                if (z)
                {
                    letterFreqMut[0] += toTransform;
                    letterFreqMut[1] += toTransform;
                }
                else{
                    letterFreqMut[i+1] += toTransform;
                }
            }
            letterFreqConst = letterFreqMut;
        }

        long long ans = 0;

        for (const auto& freq : letterFreqConst){
            ans += freq;
            ans %= MODULO;
        }

        return ans;
    }
};