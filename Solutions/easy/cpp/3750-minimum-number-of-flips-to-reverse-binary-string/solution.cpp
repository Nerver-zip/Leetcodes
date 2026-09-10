class Solution {
public:
    int minimumFlips(int n) {
        vector<int> mask;

        for (int i = 0; i < 32; ++i) {
            mask.push_back(n & 1);
            n = n >> 1;
            if(n == 0)
                break;
        }

        auto copy = mask;
        reverse(copy.begin(), copy.end());
        int ans = 0;
        for (int i = 0; i < mask.size(); ++i) {
            if(mask[i] != copy[i])
                ++ans;
        }

        return ans;
    }
};