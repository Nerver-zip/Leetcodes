class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long ans = 0, prev = INT32_MIN, consecutive = 0;
        
        for (int n : nums) {    
            if(n == 0 && prev == n)
                ++consecutive;
            else
                consecutive = 0;

            if(n == 0)
                ans += 1 + consecutive;

            prev = n;
        }

        return ans;
    }
};