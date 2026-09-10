class Solution {
public:
    int minimumPushes(string word) {
        const int n = word.size();

        return min(n, 8) + 
               min(max(n-8, 0), 8) * 2 + 
               min(max(n-16, 0), 8) * 3 + 
               min(max(0, n-24), 2) * 4;
    }
};