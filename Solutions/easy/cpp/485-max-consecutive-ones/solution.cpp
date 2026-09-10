class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, consecutive = 0;
        for (int n : nums) {
            if(n == 1)
                ++consecutive;        
            else{
                ans = max(ans, consecutive);
                consecutive = 0;
            }
        }

        return consecutive == 0 ? ans : max(consecutive, ans);
    }
};