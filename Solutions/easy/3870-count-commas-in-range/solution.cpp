class Solution {
public:
    int countCommas(int n) {
        int x = n - 999;

        return x < 0 ? 0 : x;
    }
};