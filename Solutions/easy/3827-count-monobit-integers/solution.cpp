class Solution {
public:
    int countMonobit(int n) {
        int ans = 0;
        for(unsigned int x = 0; x <= n; ++x)
            if (popcount(x) == bit_width(x))
                ++ans;
        return ans;
    }
};