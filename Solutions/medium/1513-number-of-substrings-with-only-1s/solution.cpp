class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        int consecutive = 0, ans = 0;

        for (char n : s) {
            if(n == '1')
                ++consecutive;
            else{
                ans += (1LL * (consecutive+1) * consecutive) / 2 % MOD;
                consecutive = 0;
            }
        }

        ans = consecutive > 0 ? ans + (1LL * (consecutive+1) * consecutive) / 2 % MOD : ans;

        return ans;
    }
};