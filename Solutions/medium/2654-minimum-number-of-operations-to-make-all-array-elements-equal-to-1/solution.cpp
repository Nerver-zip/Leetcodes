class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;

        for (int n : nums)
            if(n == 1)
                ++count; 
        
        if(count)
            return nums.size() - count;
        
        int minimum = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            for (int j = i+1; j < nums.size(); ++j) {
                x = gcd(x, nums[j]);
                if(x == 1)
                    minimum = min(minimum, j - i);
            }
        }

        return minimum == INT_MAX ? -1 : nums.size() + minimum - 1;
    }
};