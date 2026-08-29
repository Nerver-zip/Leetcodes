class Solution {
public:
    int mirrorDistance(int n) {
        string num = to_string(n);
        reverse(num.begin(), num.end());
        int mirrored = stoi(num);

        return abs(n - mirrored);
    }
};