class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 1;
        sort(nums.begin(), nums.end());

        int maximum = nums[0];
        int minimum = nums[0];
        
        for (int n : nums)
        {
            if(abs(n - maximum) > k || abs(n - minimum) > k){
                ans++;
                maximum = n;
                minimum = n;
            }
            else
                if(n < minimum)
                    minimum = n;
                if(n > maximum)
                    maximum = n;
        }  
        return ans;
    }
};