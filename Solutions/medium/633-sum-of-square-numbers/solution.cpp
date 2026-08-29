using ll = long long;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = (int)floor(sqrt(c));

        while (left <= right) {
            ll res = 1LL * left * left + 1LL * right * right;
            if(res == c)
                return true;
            if(res < c)
                ++left;
            else
                --right;
        }

        return false;
    }
};