class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maximum = 0;

        for (int n : nums) {
            maximum = max(maximum, n);
        }
        
        int ans = 0;
        for (int n : nums) {
            ans += abs(n - maximum);
        }

        return ans;
    }
};