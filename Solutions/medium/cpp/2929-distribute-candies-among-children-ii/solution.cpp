class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i < std::min(n, limit) + 1; ++i)
        {
            int minB = std::max(0, n - i - limit);
            int maxB = std::min(limit, n - i);
            if (minB <= maxB)
                ans += maxB - minB + 1;
        }
        return ans;
    }
};